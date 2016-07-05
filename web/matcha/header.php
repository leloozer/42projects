<?php include("functions_php.php");
if (session_status() != PHP_SESSION_ACTIVE) session_start();
?>
	<html>
		<head>
			<meta charset="utf-8">
			<title>CRUCIFUCK</title>
			<link rel="stylesheet" type="text/css" href="stylesheet/default.css" />
		</head>
		<header>
			<div class="menu">
			<img class="logo" src="img/logo.jpg">
			<div class="namesite">Crucifuck.com</div>
<?php			
if (isset($_SESSION["logged"]) && user_exists($_SESSION["logged"])) {
	$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
	$query = $bdd->query("SELECT * FROM user WHERE login='$_SESSION[logged]'");
	$perso = $query->fetchALL();
	foreach($perso as $profil){};
?>
				<div class="welcome"><p>Welcome <?php echo ($_SESSION["logged"]); ?></p>
				<a href="myprofil.php" class="button">My profil</a>
				<?php echo $profil['score'];?>
				<a href="recherche.php" class="button">Recherche</a>
				<a href="message.php" class="button">Message</a>
				<a href="logout.php" class="button">Log out</a></div>
<?php
} else {
?>
				<ul class="tabs">
						<div class="tab-content">
							<form action="login.php" method="post">
								<input type="text" name="login" placeholder="login">
								<input type="password" name="passwd" placeholder="password">
								<input type="hidden" name="submit" value="OK">
								<input type="submit" value="Log in">
								<a href="forget.php" class="button">Forgot Your Password ?</a>
							</form>
						</div>
				</ul>
<?php
}
?>
			</span>
		</div>
		</div>
		</header>
