<?php
include 'header.php';
?>
	<div id="forget">
	<h5>Forget Your Password ?</h5>
	<form action="forgetpasswd.php" method= "POST">
	<input type="text" name="login" placeholder="login">
	<input type="text" name="mail" placeholder="Your mail">
	<input type="submit" name="submit" value="OK">
	</form>
	</div>
 <?php include("footer.php"); ?>
