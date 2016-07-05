<?php
include 'header.php';
$token="";
$token =  htmlspecialchars ($_GET['token']);
?>

	<div id="forget">
	<h5>New Password</h5>
	<form action="modif.php" method= "POST">
	<input type="text" name="login" placeholder="login">
	<input type="password" name="pwd" placeholder="new password">
	<input type="password" name="confpwd" placeholder="comfirm your new password">
	<input type="hidden" name="token" value="<?php echo $token;?>">
	<input type="submit" name="submit" value="OK">
	</form>
	</div>
<?php include("footer.php"); ?>

