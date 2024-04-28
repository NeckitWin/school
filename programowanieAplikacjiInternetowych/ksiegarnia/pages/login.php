<?php
$error = "";
require "./db.php";
if(isset($_POST["signin"])) {
    $login = $_POST["login"];
    $password = $_POST["password"];
    $sql = "SELECT * FROM hasla WHERE login='$login' AND haslo='$password'";
    $result = $connection->query($sql);
    if ($result->num_rows > 0) {
        $_SESSION["username"] = $login;
        $error = 'Zalogowano';
        header("Location: index.php");
    } else {
        $error = 'Błędne dane logowania';
    }
}

if(isset($_POST["signup"])) {
    $login = $_POST["login"];
    $password = $_POST["password"];
    $repeatPassword = $_POST["repeatPassword"];
    if($password == $repeatPassword) {
        $sql = "INSERT INTO hasla (login, haslo) VALUES ('$login', '$password')";
        if ($connection->query($sql) === TRUE) {
            $error = 'Zarejestrowano';
        } else {
            $error = 'Błąd rejestracji';
        }
    } else {
        $error = 'Hasła nie są takie same';
    }
}
?>
<head>
    <link rel="stylesheet" href="./pages/styles/login.css">
</head>
<div class="login">
    <form method="POST">
        <input type="hidden" name="router" value="login">
        <label for="login">Login</label>
        <label for="password">Hasło</label>
        <label for="rPassword">Login</label>
        <label for="login">Potwierdź</label>
        <div>
            <input type="text" name="login">
        </div>
        <div>
            <input type="password" name="password">
        </div>
        <div>
            <input type="password" name="repeatPassword">
        </div>
        <div>
            <input type="submit" name="signin" value="Zaloguj">
            <input type="submit" name="signup" value="Zarejestruj">
        </div>
        <p class="errorframe">Komunikat informujący o sukcesie logowania, rejestracji lub zmianie hasła: <?php echo $error ?></p>
        <p class="yellow">Wpisz dane i wciśnij odpowiedni przycisk</p>
    </form>
    <ul>
        <li>Aby się zalogować wpisujesz <span>Login</span> oraz <span>Hasło</span> i wciskasz <span>Zaloguj</span></li>
        <li>Aby się wylogować wciskasz <span>Wyloguj</span></li>
        <li>Jeżeli jesteś nowym użytkownikiem, wpisujesz Login oraz dwukrotnie hasło - w polu <span>Hasło</span> oraz
            <span>Powtórz hasło</span> i<br>wciskasz <span>Zarejestruj</span></li>
    </ul>
</div>