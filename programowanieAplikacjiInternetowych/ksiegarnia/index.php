<?php
$site = "home";
if(isset($_GET["site"])) {
  $site = $_GET["site"];
}
?>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>księgarnia internetowa</title>
  <link rel="stylesheet" href="style.css" type="text/css" />
  <link rel="shortcut icon" type="image/x-icon" href="zadanieE14_1\grafika\favicon.ico">
</head>
<body>
   <div id="calosc">

  <?php
    require "./components/header.php"; 
    require "./components/navbar.php"; 
  ?>
    
    <div id="tresc">
      <p>zalogowany użytkownik: <?php?></p>
      <?php 
        switch ($site) {
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