<?php
?>
<head>
    <link rel="stylesheet" href="./components/styles/navbar.css" style="display: none;">
</head>
<nav class="navbar">
    <ul>
        <li><a href="index.php">Nasza Księgarnia</a></li>
        <?php
            echo !isset($_SESSION["username"]) ? "<li><a href='logowanie.php'>Logowanie</a></li>" : "";
        ?>
        <li><a href="zakupy.php">Zakupy</a></li>
        <li><a href="koszyk.php">Twój koszyk</a></li>
    </ul>
</nav>