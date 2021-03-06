<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
?>
	<?php include ("header.php")?>
<?php
if ($_SESSION['logged'] != "")
{ 


	function imagecopymerge_alpha($dst_im, $src_im, $dst_x, $dst_y, $src_x, $src_y, $src_w, $src_h, $pct){ 

		$cut = imagecreatetruecolor($src_w, $src_h); 
		imagecopy($cut, $dst_im, 0, 0, $dst_x, $dst_y, $src_w, $src_h);
		imagecopy($cut, $src_im, 0, 0, $src_x, $src_y, $src_w, $src_h);
		imagecopymerge($dst_im, $cut, $dst_x, $dst_y, 0, 0, $src_w, $src_h, $pct); 
	} 

	if (isset($_POST['cpt']) && $_POST['cpt'] != "" && isset($_POST['alpha'])) {

		list($type, $data) = explode(';', $_POST['cpt']);
		list(, $data) = explode(',', $data);
		$data = base64_decode($data);
		file_put_contents( IMAGE .'/tmp1.png', $data);
		$im = imagecreatefrompng(IMAGE .'/tmp1.png');
		$alpha = imagecreatefrompng(img .'/'.$_POST['alpha'].'.png');
		imagecopymerge_alpha($im, $alpha, 0, 0, 0, 0, imagesx($alpha), imagesy($alpha), 100);
		$login = $_SESSION['logged'];
		$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
		$query = $bdd->query("SELECT * FROM image");
		$image_id = time();
		$image_name = $login.'-'. $image_id . '.png';
		imagepng($im,  IMAGE .'/'. $image_name);
		// free memory
		imagedestroy($im);
		$req = $bdd->prepare('INSERT INTO camagru.image (login, photo, likes) VALUES (:login, :photo, :likes)');
		$req->execute(array(
			'login' => $login,
			'photo' => $image_name,
			'likes' => 0));
		echo "<meta http-equiv='refresh' content='0;URL=shooting.php'>";
		die();

	}
	if (isset($_FILES['image']) && isset($_POST['alpha'])) {
		$image = $_FILES['image'];
		$extension = pathinfo($image['name'], PATHINFO_EXTENSION);
		if (in_array($extension, array('jpg', 'png'))){

			$user = $_SESSION['logged'];
			$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
			$image_id = time();
			$image_name = $user.'-'. $image_id . '.png';
			$bdd->query("SELECT * FROM image");
			
			move_uploaded_file($image['tmp_name'], IMAGE .'/'. $image_name);
			if ($extension == 'jpg')
				$im = imagecreatefromjpeg(IMAGE .'/'. $image_name);
			else if ($extension == 'png')
				$im = imagecreatefrompng(IMAGE .'/'. $image_name);
			$alpha = imagecreatefrompng(img .'/'.$_POST['alpha'].'.png');
			imagecopymerge_alpha($im, $alpha, 0, 0, 0, 0, imagesx($alpha), imagesy($alpha), 100);
			imagepng($im,  IMAGE .'/'. $image_name);
			imagedestroy($im);
			$req = $bdd->prepare('INSERT INTO camagru.image (login, photo, likes) VALUES (:login, :photo, :likes)');
			$req->execute(array(
				'login' => $user,
				'photo' => $image_name,
				'likes' => 0));
		}
		echo "<meta http-equiv='refresh' content='0;URL=shooting.php'>";
		die();
	}
?>
	<div>
		<video id="video"></video>
		<button id="startbutton">Prendre une photo</button>
		<canvas style="display: none" id="canvas"></canvas>
		<img id="photo" src="">

		<form action="#" method="post" enctype="multipart/form-data">
			<div style="text-align: center;">
			<ul class="selection">
				<li style="display:inline-block;"><label><img src="img/alphatest1.png"><input type="radio" name="alpha" value="alphatest1" checked="checked"></label></li>
				<li style="display:inline-block;"><label><img src="img/alphatest2.png"><input type="radio" name="alpha" value="alphatest2"></label></li>
				<li style="display:inline-block;"><label><img src="img/alphatest3.png"><input type="radio" name="alpha" value="alphatest3"></label></li>
				<li style="display:inline-block;"><label><img src="img/alphatest4.png"><input type="radio" name="alpha" value="alphatest4"></label></li>
				<li style="display:inline-block;"><label><img src="img/alphatest5.png"><input type="radio" name="alpha" value="alphatest5"></label></li>
			</ul>
			</div>
			<div>
				<input type="file" name="image">
			</div>
			<div >
				<input id="cpt" type="hidden" name="cpt">
			</div>
			<button type="submit">Envoyer</button>
		</form>
	</div>

	<script>
	(function() {

		var streaming = false,
			video        = document.querySelector('#video'),
	  cover        = document.querySelector('#cover'),
	  canvas       = document.querySelector('#canvas'),
	  photo        = document.querySelector('#photo'),
	  startbutton  = document.querySelector('#startbutton'),
	  cpt		   = document.querySelector('#cpt'),
	  width = 320,
	  height = 0;

		navigator.getMedia = ( navigator.getUserMedia ||
			navigator.webkitGetUserMedia ||
			navigator.mozGetUserMedia ||
			navigator.msGetUserMedia);

		navigator.getMedia(
			{
				video: true,
					audio: false
			},
			function(stream) {
				if (navigator.mozGetUserMedia) {
					video.mozSrcObject = stream;
				} else {
					var vendorURL = window.URL || window.webkitURL;
					video.src = vendorURL.createObjectURL(stream);
				}
				video.play();
			},
				function(err) {
					console.log("An error occured! " + err);
				}
		);

		video.addEventListener('canplay', function(ev){
			if (!streaming) {
				height = video.videoHeight / (video.videoWidth/width);
				video.setAttribute('width', width);
				video.setAttribute('height', height);
				canvas.setAttribute('width', width);
				canvas.setAttribute('height', height);
				streaming = true;
			}
		}, false);

		function takepicture() {
			canvas.width = width;
			canvas.height = height;
			canvas.getContext('2d').drawImage(video, 0, 0, width, height);
			var data = canvas.toDataURL('image/png');
			photo.setAttribute('src', data);
			cpt.setAttribute('value', data);
		}

		startbutton.addEventListener('click', function(ev){
			takepicture();
		}, false);

	})();
	</script>
<?php 
	include"mygallerie.php";
}
else
{ 
	echo"Inscrit toi batard\n";
} ?>
<?php include("footer.php"); ?>

