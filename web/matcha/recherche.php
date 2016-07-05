<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
include ("header.php");
if ($_SESSION['logged'] != "")
{
	$bdd = new PDO('mysql:host=localhost;dbanme=matcha', 'root', '');
	//	$query = $bdd->query("SELECT * FROM user WHERE login='$_SESSION[logged]'");
	//	$perso = $query->fetch();
?>
<div id="advanced-search">
		<section id="search-page">
			<form id="search-form" method="post" action="search.php">
				<div class="bloc clearfix">
					<div class="search-header">
						<span>Votre recherche <span class="total-criteria"></span></span>
					</div>
					<div class="search-categories main-criterias">
						<div class="form-row">
							<label>Son âge :</label><div class="input-container age">
								de <select name="age[min]">
<option value="">...</option>
<option value="1" selected="selected">1</option>
<option value="2">2</option>
<option value="3">3</option>
<option value="4">4</option>
<option value="5">5</option>
<option value="6">6</option>
<option value="7">7</option>
<option value="8">8</option>
<option value="9">9</option>
<option value="10">10</option>
<option value="11">11</option>
<option value="12">12</option>
<option value="13">13</option>
<option value="14">14</option>
<option value="15">15</option>
<option value="16">16</option>
<option value="17">17</option>
<option value="18">18</option>
<option value="19">19</option>
<option value="20">20</option>
<option value="21">21</option>
<option value="22">22</option>
<option value="23">23</option>
<option value="24">24</option>
<option value="25">25</option>
<option value="26">26</option>
<option value="27">27</option>
<option value="28">28</option>
<option value="29">29</option>
<option value="30">30</option>
<option value="31">31</option>
<option value="32">32</option>
<option value="33">33</option>
<option value="34">34</option>
<option value="35">35</option>
<option value="36">36</option>
<option value="37">37</option>
<option value="38">38</option>
<option value="39">39</option>
<option value="40">40</option>
<option value="41">41</option>
<option value="42">42</option>
<option value="43">43</option>
<option value="44">44</option>
<option value="45">45</option>
<option value="46">46</option>
<option value="47">47</option>
<option value="48">48</option>
<option value="49">49</option>
<option value="50">50</option>
<option value="51">51</option>
<option value="52">52</option>
<option value="53">53</option>
<option value="54">54</option>
<option value="55">55</option>
<option value="56">56</option>
<option value="57">57</option>
<option value="58">58</option>
<option value="59">59</option>
<option value="60">60</option>
<option value="61">61</option>
<option value="62">62</option>
<option value="63">63</option>
<option value="64">64</option>
<option value="65">65</option>
<option value="66">66</option>
<option value="67">67</option>
<option value="68">68</option>
<option value="69">69</option>
<option value="70">70</option>
<option value="71">71</option>
<option value="72">72</option>
<option value="73">73</option>
<option value="74">74</option>
<option value="75">75</option>
<option value="76">76</option>
<option value="77">77</option>
<option value="78">78</option>
<option value="79">79</option>
<option value="80">80</option>
<option value="81">81</option>
<option value="82">82</option>
<option value="83">83</option>
<option value="84">84</option>
<option value="85">85</option>
<option value="86">86</option>
<option value="87">87</option>
<option value="88">88</option>
<option value="89">89</option>
<option value="90">90</option>
<option value="91">91</option>
<option value="92">92</option>
<option value="93">93</option>
<option value="94">94</option>
<option value="95">95</option>
<option value="96">96</option>
<option value="97">97</option>
<option value="98">98</option>
<option value="99">99</option>
</select> à <select name="age[max]">
<option value="">...</option>
<option value="1">1</option>
<option value="2">2</option>
<option value="3">3</option>
<option value="4">4</option>
<option value="5">5</option>
<option value="6">6</option>
<option value="7">7</option>
<option value="8">8</option>
<option value="9">9</option>
<option value="10">10</option>
<option value="11">11</option>
<option value="12">12</option>
<option value="13">13</option>
<option value="14">14</option>
<option value="15">15</option>
<option value="16">16</option>
<option value="17">17</option>
<option value="18">18</option>
<option value="19">19</option>
<option value="20">20</option>
<option value="21">21</option>
<option value="22">22</option>
<option value="23">23</option>
<option value="24">24</option>
<option value="25">25</option>
<option value="26">26</option>
<option value="27">27</option>
<option value="28">28</option>
<option value="29">29</option>
<option value="30">30</option>
<option value="31">31</option>
<option value="32">32</option>
<option value="33">33</option>
<option value="34">34</option>
<option value="35">35</option>
<option value="36">36</option>
<option value="37">37</option>
<option value="38">38</option>
<option value="39">39</option>
<option value="40">40</option>
<option value="41">41</option>
<option value="42">42</option>
<option value="43">43</option>
<option value="44">44</option>
<option value="45">45</option>
<option value="46">46</option>
<option value="47">47</option>
<option value="48">48</option>
<option value="49">49</option>
<option value="50">50</option>
<option value="51">51</option>
<option value="52">52</option>
<option value="53">53</option>
<option value="54">54</option>
<option value="55">55</option>
<option value="56">56</option>
<option value="57">57</option>
<option value="58">58</option>
<option value="59">59</option>
<option value="60">60</option>
<option value="61">61</option>
<option value="62">62</option>
<option value="63">63</option>
<option value="64">64</option>
<option value="65">65</option>
<option value="66">66</option>
<option value="67">67</option>
<option value="68">68</option>
<option value="69">69</option>
<option value="70">70</option>
<option value="71">71</option>
<option value="72">72</option>
<option value="73">73</option>
<option value="74">74</option>
<option value="75">75</option>
<option value="76">76</option>
<option value="77">77</option>
<option value="78">78</option>
<option value="79">79</option>
<option value="80">80</option>
<option value="81">81</option>
<option value="82">82</option>
<option value="83">83</option>
<option value="84">84</option>
<option value="85">85</option>
<option value="86">86</option>
<option value="87">87</option>
<option value="88">88</option>
<option value="89">89</option>
<option value="90">90</option>
<option value="91">91</option>
<option value="92">92</option>
<option value="93">93</option>
<option value="94">94</option>
<option value="95">95</option>
<option value="96">96</option>
<option value="97">97</option>
<option value="98">98</option>
<option value="99" selected="selected">99</option>
</select></div>
						</div>
<div class="form-row no-slider"  data-visible-when-field="by" data-visible-when-value="region">
							<label for="their-region">Sa région :</label>

								<select name="region" data-countries-field="their-country" id="their-region">
<option value="" selected="selected">Toutes les régions</option>
<option value="1">Alsace</option>
<option value="2">Aquitaine</option>
<option value="3">Auvergne</option>
<option value="4">Basse-Normandie</option>
<option value="5">Bourgogne</option>
<option value="6">Bretagne</option>
<option value="7">Centre</option>
<option value="8">Champagne-Ardenne</option>
<option value="22">Corse</option>
<option value="23">DOM-TOM</option>
<option value="9">Franche-Comté</option>
<option value="10">Haute-Normandie</option>
<option value="11">Île-de-France</option>
<option value="12">Languedoc-Roussillon</option>
<option value="13">Limousin</option>
<option value="14">Lorraine</option>
<option value="15">Midi-Pyrénées</option>
<option value="16">Nord-Pas-de-Calais</option>
<option value="17">PACA</option>
<option value="18">Pays de la Loire</option>
<option value="19">Picardie</option>
<option value="20">Poitou-Charentes</option>
<option value="21">Rhône-Alpes</option>
</select>
<div class="form-row">
							<label for="their-nick">Son pseudo :</label>
							<div class="input-container nickname">
								<input id="their-nick" name="pseudo" type="text" class="fat-input" value="" />
							</div>
						
<label>Score minimum :</label>
<select name="distance[min]">
<option value="0" selected="selected">0</option>
<option value="20">20</option>
<option value="50">50</option>
<option value="100">100</option>
<option value="150">150</option>
<option value="200">200</option>
<option value="300">300</option>
<option value="500">500</option>
<option value="1000">1000</option>
<option value="2000">2000</option>
<option value="3000">3000</option>
<option value="5000">5000</option>
</select>

<label>Tag:</label>
<ul>
<?php
	$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
	$query = $bdd->query("SELECT * FROM tag");
	$la = $query->fetchALL();
	$i = 0;
	foreach($la as $tag):
		?>
		<li><input type="checkbox" name="tag" value="<?php echo $tag[name];?>"><?php echo $tag["name"];?></li>
<?php  $i++;
	endforeach; ?>
</ul>
<input type="submit" value="recherchez"></form>
</div>

<?php

include("parcours.php");

}
else
{
	echo "Inscrit toi mon enfant!";
}
?>
