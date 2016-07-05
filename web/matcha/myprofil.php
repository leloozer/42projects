<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
?>
	<?php include ("header.php");?>
<?php
if ($_SESSION['logged'] != "")
{
	$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
	$query = $bdd->query("SELECT * FROM user WHERE login='$_SESSION[logged]'");
	$qry = $bdd->query("SELECT * FROM image WHERE login='$_SESSION[logged]'");
	$perso = $query->fetchAll();
	$img = $qry->fetchAll();
	foreach($perso as $profil){};

	if (isset ($_GET['ok']))
	{
		$name = htmlspecialchars($_POST['name']);
		$firstname = htmlspecialchars($_POST['firstname']);
		$mail = htmlspecialchars($_POST['mail']);
		$bio = htmlspecialchars($_POST['bio']);
		$sexe = htmlspecialchars($_POST['sexe']);
		$orientation = htmlspecialchars($_POST['orientation']);
		$name = trim ($name);
		$firstname = trim ($firstname);
		$mail = trim ($mail);
		$bio = trim ($bio);
		if ($name != null && $name != $profil['name'])
		{
			$req= $bdd->prepare("UPDATE user SET name= :name WHERE login='$_SESSION[logged]'");
			$req->execute(array('name' => $name));
		}
		if ($firstname != null && $firstname != $profil['firstname'])
		{
			$req= $bdd->prepare("UPDATE user SET firstname= :firstname WHERE login='$_SESSION[logged]'");
			$req->execute(array('firstname' => $firstname));
		}
		if ($mail != null && $mail != $profil['mail'])
		{
			$req= $bdd->prepare("UPDATE user SET mail= :mail WHERE login='$_SESSION[logged]'");
			$req->execute(array('mail' => $mail));
		}
		if ($bio != null && $bio != $profil['bio'])
		{
			$req= $bdd->prepare("UPDATE user SET bio= :bio WHERE login='$_SESSION[logged]'");
			$req->execute(array('bio' => $bio));
		}
		if ($sexe != null && $sexe != $profil['sexe'])
		{
			$req= $bdd->prepare("UPDATE user SET sexe= :sexe WHERE login='$_SESSION[logged]'");
			$req->execute(array('sexe' => $sexe));
		}
		if ($orientation != null && $orientation != $profil['orientation'])
		{
			$req= $bdd->prepare("UPDATE user SET orientation= :orientation WHERE login='$_SESSION[logged]'");
			$req->execute(array('orientation' => $orientation));
		}
		echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
		die();
	}

	// for upload photo
	if (isset($_FILES['image']['name']))
	{
		$image = $_FILES['image'];
		$extension = pathinfo($image['name'], PATHINFO_EXTENSION);
		if (in_array($extension, array('jpg', 'jpeg', 'png')))
		{
			$user = $_SESSION['logged'];
			$image_id = time();
			$image_name = $user . '-' . $image_id . '.png';
			move_uploaded_file($image['tmp_name'], IMAGE . '/' . $image_name);
			$exist = $bdd->prepare("SELECT COUNT(*) FROM matcha.image WHERE login='$_SESSION[logged]'");
			$exist->execute();
			$data = $exist->fetch(PDO::FETCH_ASSOC);
			print_r ($data);
			if ($data['COUNT(*)'] == 0)
			{
				$req = $bdd->prepare('INSERT INTO matcha.image (login, photo, profil) VALUES (:login, :photo, :profil)');
				$req->execute(array(
					'login' => $user,
					'photo' => $image_name,
					'profil' => 1));
			}
			else
			{	
				$req = $bdd->prepare('INSERT INTO matcha.image (login, photo, profil) VALUES (:login, :photo, :profil)');
				$req->execute(array(
					'login' => $user,
					'photo' => $image_name,
					'profil' => 0));
			}
		}
		echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
		die();
	}

	if (isset($_GET[delete]))
	{
		$q = $bdd->query("SELECT * FROM matcha.image WHERE photo='$_GET[delete]'");
		$forsup = $q->fetch();
		if ($forsup[login] === $_SESSION[logged])
		{
			unlink(IMAGE . '/' . $forsup[photo]);
			$bdd->query("DELETE FROM image WHERE photo='$_GET[delete]'");
		}
		echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
		die();
	}

	if (isset($_GET[forprofil]))
	{
		$q = $bdd->query("SELECT * FROM matcha.image WHERE photo='$_GET[forprofil]'");
		$forprofil = $q->fetch();
		if ($forprofil[login] === $_SESSION[logged])
		{
			$req = $bdd->prepare("UPDATE matcha.image SET profil= :profil  WHERE login='$_SESSION[logged]'");
			$req->execute(array('profil' => 0));
			$req = $bdd->prepare("UPDATE matcha.image SET profil= :profil  WHERE photo='$forprofil[photo]'");
			$req->execute(array('profil' => 1));
		}
		echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
		die();
	}
?>

<body>
	<div>
		<h6>Photo</h6>
<?php $i=0;
foreach($img as $image) :?>
		<img src= "IMAGE/<?php echo $image['photo'];?>">
		<a href="?delete=<?php echo $image['photo']?>">Delete</a>
		<a href="?forprofil=<?php echo $image['photo']?>">Definir en photo de profil</a>

<?php 
	$i++;
endforeach;
if($i < 5)
{?>
		<div>
			<form enctype="multipart/form-data" action="myprofil.php" method="POST">
			<input type="file" name="image">
			<input type="submit" value="Ajoutez une photo">
			</form>		
		</div>
<?php	}
?>	
		</div>
	<form action="?ok=#" method="POST">
		<div>
		<h6>Name</h6>
		<input type="text" name="name" placeholder="<?php echo $profil['name'];?>">
		</div>
		<div>
		<h6>FirstName</h6>
		<input type="text" name="firstname" placeholder="<?php echo $profil['firstname'];?>">
		</div>
		<div>
		<h6>Mail</h6>
		<input type="text" name="mail" placeholder="<?php echo $profil['mail'];?>">
		</div>
		<div>
		<h6>Sexe</h6>
		<ul>
		<li style="display:inline-block;">Homme<input type="radio" name="sexe" value="1" <?php if($profil['sexe'] == "" || $profil['sexe'] == 1){ echo "checked='checked'"; }?> ></li>
		<li style="display:inline-block;">Femme<input type="radio" name="sexe" value="2" <?php if($profil['sexe'] == 2){ echo "checked='checked'";}?>></li>
		</ul>
		</div>
		<div>
		<h6>Orientation sexuelle</h6>
		<ul>
		<li style="display:inline-block;">Heterosexuel<input type="radio" name="orientation" value="1" <?php if($profil['orientation'] == 1){  echo"checked='checked'"; }?>></li>
		<li style="display:inline-block;">Homosexuel<input type="radio" name="orientation" value="2" <?php if($profil['orientation'] == 2){ echo "checked='checked'"; }?>></li>
		<li style="display:inline-block;">Bisexuel<input type="radio" name="orientation" value="3" <?php if($profil['orientation'] == 3 || $profil['orientation'] == ""){ echo "checked='checked'";}?>></li>
		</ul>
		</div>
		<div>
		<h6>Biographie</h6>
		<textarea name="bio"><?php echo $profil['bio'];?></textarea>
		</div>
		<button type="submit">Mettre à jour</button>
	</form>
	<div>
		<h6>Intérêt</h6>
		<?include "tag.php"?>
	</div>
	


<? // debut localisation ?>

	<script>
	function initialize() {
		map = new google.maps.Map(document.getElementById("map_canvas"), {
		zoom: 19,
			center: new google.maps.LatLng(48.8585, 2.347198),
			mapTypeId: google.maps.MapTypeId.ROADMAP
	});   
} 

if (navigator.geolocation)
	var watchId = navigator.geolocation.watchPosition(successCallback,
		null,
{enableHighAccuracy:true});
else
	alert("Votre navigateur ne prend pas en compte la géolocalisation HTML5");    

function successCallback(position){
	map.panTo(new google.maps.LatLng(position.coords.latitude, position.coords.longitude));
	var marker = new google.maps.Marker({
		position: new google.maps.LatLng(position.coords.latitude, position.coords.longitude), 
		map: map}); 
}
</script>
	<div id="map_canvas">
		<div onload="initialize()">
		</div>
	</div>
			<script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=true"></script> 

<?php


// fin localisation

}
else
{ 
	echo"Inscrit toi mon fils\n";
} ?>
</body>
