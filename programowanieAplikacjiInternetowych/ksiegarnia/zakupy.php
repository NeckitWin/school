<?php
require "./sesja.php";
require "./db.php";
global $connection;
$error = "";
if (isset($_POST["kup"])) {
    foreach ($_POST as $key => $value) {
        if (substr($key, 0, 4) == "add_" && $value == "on") {
            $isbn = substr($key, 4);
            $quantity = $_POST["quantity_" . $isbn];
            if ($quantity > 0) {
                $username = $_SESSION["username"];
                $sql = "SELECT id_hasla FROM hasla WHERE login = ?";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("s", $username);
                $stmt->execute();
                $result = $stmt->get_result();
                $row = $result->fetch_assoc();
                $id_hasla = $row["id_hasla"];

                $sql = "SELECT stan FROM ksiazki WHERE isbn = ?";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("s", $isbn);
                $stmt->execute();
                $result = $stmt->get_result();
                $row = $result->fetch_assoc();
                if ($quantity > $row["stan"]) {
                    $error = "Nie ma tylu książek na stanie";
                    continue;
                }

                $sql = "INSERT INTO koszyk (isbn, id_hasla, ilosc) VALUES (?, ?, ?)";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("ssi", $isbn, $id_hasla, $quantity);
                if ($stmt->execute() === FALSE) {
                    $error = $sql . "<br>" . $connection->error;
                }

                $sql = "UPDATE ksiazki SET stan = stan - ? WHERE isbn = ?";
                $stmt = $connection->prepare($sql);
                $stmt->bind_param("is", $quantity, $isbn);
                if ($stmt->execute() === FALSE) {
                    $error = $sql . "<br>" . $connection->error;
                } else {
                    header("Location: koszyk.php");
                }
            }
        }
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
    <link rel="stylesheet" href="styles/zakupy.css">
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
        <form class="zakupy" method="post">
            <table>
                <thead>
                <tr>
                    <th>Tytuł</th>
                    <th>Autor</th>
                    <th>ISBN</th>
                    <th>Cena (zł)</th>
                    <th>Stan (sztuk)</th>
                    <th>Kupuję</th>
                    <th>Sztuk</th>
                </tr>
                </thead>
                <tbody>
                <?php
                global $connection;
                $sql = "SELECT * FROM ksiazki";
                $result = $connection->query($sql);
                if ($result->num_rows > 0) {
                    while ($row = $result->fetch_assoc()) {
                        echo "<tr>";
                        echo "<td>" . $row["tytul"] . "</td>";
                        echo "<td>" . $row["autor"] . "</td>";
                        echo "<td>" . $row["isbn"] . "</td>";
                        echo "<td>" . $row["cena"] . "</td>";
                        echo "<td>" . $row["stan"] . "</td>";
                        $add = "add_" . $row["isbn"];
                        $quantity = "quantity_" . $row["isbn"];
                        echo "<td><input type='checkbox' name='$add'></td>";
                        echo "<td><input type='number' name='$quantity' min='1'></td>";
                        echo "</tr>";
                    }
                }
                ?>
                </tbody>
            </table>
            <p class="error"><?php echo $error ?></p>
            <input type="submit" name="kup" value="Wrzuć do koszyka zaznaczone książki">
        </form>
    </div>

    <?php
    require "./components/footer.php"
    ?>
</div>
</body>
</html>