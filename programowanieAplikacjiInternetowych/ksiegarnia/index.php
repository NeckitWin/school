<?php
require "./sesja.php";
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
            echo isset($_SESSION["username"]) ? $_SESSION["username"] . "<form method='POST'><button type='submit' name='logout'>Wyloguj</button></form>" : "brak"; ?>
        </div>
        <h3>Nasza księgarnia spełni wszystkie Twoje oczekiwania</h3>
        <ol>
            <li>Książki otrzymasz najpożniej 3 dni po złożeniu zamówienia
                <ul>
                    <li >wysyłka sprawdzoną firmą kurierską</li>
                    <li>koszt wysyłki to tylko 5 zl</li>
                </ul>
            </li>
            <li>Po zakupie 10 książek nie płacisz za kuriera</li>
            <li>W przypadku uszkodzenia przesyłki zwracamy 100% kosztów lub bezpłatnie wysyłamy ten sam towar</li>
            <li>Szeroki wybór - posiadamy aktualnie 2 miliony tytułów!</li>
        </ol>
        <picture><img alt="czyta" src="zadanieE14_1/grafika/czyta_anim.gif" /></picture>
    </div>

    <?php
    require "./components/footer.php"
    ?>
</div>
</body>
</html>