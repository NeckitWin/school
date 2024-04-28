<?php
session_start();
$router = "home";
if (isset($_GET["router"])) {
    $router = $_GET["router"];
}
if (isset($_GET["logout"])) {
    session_unset();
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
</head>
<body>
<div id="calosc">

    <?php
    require "./components/header.php";
    require "./components/navbar.php";
    ?>

    <div id="tresc">
        <div class="yellow logout">Zalogowany użytkownik: <?php
            echo isset($_SESSION["username"]) ? $_SESSION["username"] . "<form><button type='submit' name='logout'>Wyloguj</button></form>" : "brak"; ?>
        </div>
        <?php
        switch ($router) {
            case 'home':
                require "./pages/main.php";
                break;
            case 'login':
                require "./pages/login.php";
                break;
            case 'zakupy':
                require "./pages/zakupy.php";
                break;
            case 'koszyk':
                require "./pages/koszyk.php";
                break;
        }
        ?>
    </div>

    <?php
    require "./components/footer.php"
    ?>
</div>
</body>
</html>