<?php
require "./sesja.php";
require_once "./db.php";
global $connection;
$sum = 0;
$thanks = "";

if (isset($_POST["buy"])) {
    $username = $_SESSION["username"];
    $sql = "SELECT id_hasla FROM hasla WHERE login = ?";
    $stmt = $connection->prepare($sql);
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();
    $id_hasla = $row["id_hasla"];

    // Check if there are any items in the cart
    $sql = "SELECT COUNT(*) as count FROM koszyk WHERE id_hasla = ?";
    $stmt = $connection->prepare($sql);
    $stmt->bind_param("i", $id_hasla);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();
    if ($row["count"] == 0) {
        $thanks = "Nie wybrano żadnych produktów do zakupu";
    } else {
        $sql = "DELETE FROM koszyk WHERE id_hasla = ?";
        $stmt = $connection->prepare($sql);
        $stmt->bind_param("i", $id_hasla);
        if ($stmt->execute() === FALSE) {
            echo "Error: " . $sql . "<br>" . $connection->error;
        } else {
            $thanks = "Dziękujemy za zakupy w naszym sklepie, Twoje zamówienie zostało przesłane do realizacji";
        }
    }
}

if (isset($_POST["remove"])) {
    $username = $_SESSION["username"];
    $sql = "SELECT id_hasla FROM hasla WHERE login = ?";
    $stmt = $connection->prepare($sql);
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();
    $id_hasla = $row["id_hasla"];

    $sql = "SELECT COUNT(*) as count FROM koszyk WHERE id_hasla = ?";
    $stmt = $connection->prepare($sql);
    $stmt->bind_param("i", $id_hasla);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();
    if ($row["count"] == 0) {
        $thanks = "Koszyk jest pusty";
    } else {
        $sql = "SELECT isbn, ilosc FROM koszyk WHERE id_hasla = ?";
        $stmt = $connection->prepare($sql);
        $stmt->bind_param("i", $id_hasla);
        $stmt->execute();
        $result = $stmt->get_result();

        while ($row = $result->fetch_assoc()) {
            $isbn = $row["isbn"];
            $quantity = $row["ilosc"];

            $sql = "UPDATE ksiazki SET stan = stan + ? WHERE isbn = ?";
            $stmt = $connection->prepare($sql);
            $stmt->bind_param("is", $quantity, $isbn);
            if ($stmt->execute() === FALSE) {
                $thanks = "Error: " . $sql . "<br>" . $connection->error;
            }

            $sql = "DELETE FROM koszyk WHERE isbn = ? AND id_hasla = ?";
            $stmt = $connection->prepare($sql);
            $stmt->bind_param("si", $isbn, $id_hasla);
            if ($stmt->execute() === FALSE) {
                $thanks = "Error: " . $sql . "<br>" . $connection->error;
            }
        }
        $thanks = "Koszyk został opróżniony";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width">
    <title>księgarnia internetowa</title>
    <link rel="stylesheet" href="style.css" type="text/css"/>
    <link rel="shortcut icon" type="image/x-icon" href="zadanieE14_1\grafika\favicon.ico">
    <link rel="stylesheet" href="./styles/zakupy.css">
</head>
<body>
<div id="calosc">

    <?php
    require "./components/header.php";
    require "./components/navbar.php";
    ?>

    <div id="tresc">
        <div class="yellow logout">Zalogowany użytkownik: <?php
            echo isset($_SESSION["username"]) ? $_SESSION["username"] . "<form method='POST'><button type='submit' name='logout'>Wyloguj</button></form>" : "brak"; ?>
        </div>

        <?php
            if (!isset($_SESSION['username'])) {
                echo "<p>Zaloguj się, aby zobaczyć zawartość koszyka</p>";
                echo "<a href='logowanie.php'>Zaloguj się</a>";
                return;
            }
        ?>

        <form class="zakupy" method="POST">

            <table>
                <thead>
                <tr>
                    <th>Tytuł</th>
                    <th>Autor</th>
                    <th>ISBN</th>
                    <th>Cena (zł)</th>
                    <th>Sztuk</th>
                    <th>Wartosc</th>
                </tr>
                </thead>
                <tbody>
                <?php
                $username = $_SESSION["username"];
                $sql = "SELECT id_hasla FROM hasla WHERE login = ?";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("s", $username);
                $stmt->execute();
                $result = $stmt->get_result();
                $row = $result->fetch_assoc();
                $id_hasla = $row["id_hasla"];

                $sql = "SELECT ksiazki.tytul, ksiazki.autor, koszyk.isbn, ksiazki.cena, koszyk.ilosc FROM koszyk INNER JOIN ksiazki ON koszyk.isbn = ksiazki.isbn WHERE koszyk.id_hasla = ?";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("i", $id_hasla);
                $stmt->execute();
                $result = $stmt->get_result();

                while ($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>" . $row["tytul"] . "</td>";
                    echo "<td>" . $row["autor"] . "</td>";
                    echo "<td>" . $row["isbn"] . "</td>";
                    echo "<td>" . $row["cena"] . "</td>";
                    echo "<td>" . $row["ilosc"] . "</td>";
                    echo "<td>" . $row["cena"] * $row["ilosc"] . "</td>";
                    echo "</tr>";
                    $sum += $row["cena"] * $row["ilosc"];
                }
                ?>
                </tbody>
            </table>
                  <?php echo "<p>" . $sum<=0  ? "Brak produktów w koszyku" : "Wartość książek w koszyku: " . $sum . "</p>"; ?>
            <div>
                <input type="submit" name="buy" value="Zamawiam">
                <input type="submit" name="remove" value="Usuń towary z koszyka">
            </div>
            <h3><?php echo $thanks ?></h3>
        </form>
    </div>

    <?php
    require "./components/footer.php"
    ?>
</div>
</body>
</html>