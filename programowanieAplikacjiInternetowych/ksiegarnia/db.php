<?php
$host = "localhost";
$user = "root";
$password = "";
$database = "ksiegarnia";

$connection = new mysqli($host, $user, $password, $database);

if ($connection->connect_error) {
    die("Błąd połączenia z bazą danych: " . $connection->connect_error);
}
?>