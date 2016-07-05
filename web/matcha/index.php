<?php
include ("header.php"); ?>

	<div class="index">
	<div class="cover" style="background: url('img/background.jpg'); height: 600px; background-size: cover;">
	<div class="register">
	<h4 align="center">INSCRIT TOI JEUNE ENFANT</h4>
	<form action="create.php" method="post">
		<label>Login</label>
		<input type="text" name="login" placeholder="login">
		<label>Age </label>
		<input type="text" name="age" placeholder="age">
		<label>Name</label>
		<input type="text" name="name" placeholder="name">
		<label>Firstname</label>
		<input type="text" name="firstname" placeholder="firstname">
		<label>Password</label>
		<input type="password" name="passwd" placeholder="password">
		<label>Confirm Password</label>
		<input type="password" name="confpass" placeholder="confirm password">
		<input type="hidden" name="submit" value="OK">
		<label>Mail</label>
		<input type="text" name="mail" placeholder="mail"/>
		<input type="submit" value="Register">
	</form>
	</div>
	</div>
	</div>


<?php
include ("footer.php");
?>
