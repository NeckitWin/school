<?php
    require "./db.php";
?>
<head>
    <link rel="stylesheet" href="./pages/styles/zakupy.css">
</head>
<form class="zakupy">
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
                echo "<td><input type='checkbox' name='kupuje'></td>";
                echo "<td><input type='number' name='sztuk' min='1'></td>";
                echo "</tr>";
            }
        }
        ?>
        </tbody>
    </table>
    <input type="submit" name="kup" value="Wrzuć do koszyka zaznaczone książki">
</form>

