<?php
include('functions_php.php');
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Camagru</title>
		<link rel="stylesheet" type="text/css" href="stylesheets/default.css">
		<link rel="stylesheet" type="text/css" href="stylesheets/forget.css">	
</head>
	<body>
		<header>
			<div id="logo">
				<h1>Camagru</h1>
			</div>
			<div id="menu">
				<a href="gallerie.php" style="text-align:center;">Galerie</a>
			</div>
		</header>
		<div id="page-top">
			<span id="page-short-info">
<?php
if (isset($_SESSION["logged"]) && user_exists($_SESSION["logged"])) {
	echo ($_SESSION['logged']);
?>
				<div class="welcome"><p>Welcome <?php echo ($_SESSION["logged"]); ?></p></div>
				<a href="shooting.php" class="button">Shoot me!</a>
				<a href="logout.php" class="button">Log out</a>
<?php
} else {
?>
				<ul class="tabs">
					<li>
						<input type="radio" checked name="tabs" id="tab-login">
						<label class="tab-login" for="tab-login">Log in</label>
						<div class="tab-content">
							<form action="login.php" method="post">
								<input type="text" name="login" placeholder="login">
								<input type="password" name="passwd" placeholder="password">
								<input type="hidden" name="submit" value="OK">
								<input type="submit" value="Log in">
								<a href="forget.php" class="button">Forgot Your Password ?</a>
							</form>
						</div>
					</li>
					<li>
						<input type="radio" name="tabs" id="tab-register">
						<label class="tab-register" for="tab-register">Register</label>
						<div class="tab-content">
							<form action="create.php" method="post">
								<input type="text" name="login" placeholder="login">
								<input type="password" name="passwd" placeholder="password">
								<input type="password" name="confpass" placeholder="confirm password">
								<input type="hidden" name="submit" value="OK">
									<input type="text" name="mail" placeholder="mail"/>
								<input type="submit" value="Register">
								</div>
							</form>
						</div>
					</li>
				</ul>
<?php
}
?>
			</span>
		</div>
