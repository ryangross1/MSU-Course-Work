<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
    <title>User Listing</title>
</head>
<body>
    <h1 class="display-1">User Listings</h1>
    <div class="container">
    <h2>Newly Added</h2>
<!-- 
    NOTE: this is our backend (server side) code. 
    1. User cannot see this code -- unlike HTML/CSS/JavaScript
    2. This is how we will do database opperations (DB is also on server)
-->    

<?php
// DYNAMIC HTML
$firstname = $_GET['apiFirst'];
$lastname = $_GET['apiLast'];
$country = $_GET['apiCountry'];

echo "<div class='row'>";
echo "<div class='col-md'>";
  echo "<p class='aler alert-info'><strong>$firstname</strong> has been added.</p>";
echo "</div>";


// DATABASE OPERATIONS:
// https://www.w3schools.com/php/php_mysql_insert.asp
$servername = "localhost";
$username = "user62";
$password = "62hoax";
$dbname = "db62";

// Create connection (assuming these exist -- we set up the DB on the CLI)
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// SQL OPPERATIONS
$sql = "INSERT INTO randuser (firstname, lastname, country) VALUES ('$firstname', '$lastname', '$country')";
echo "<div class='col-md'>";
if ($conn->query($sql) === TRUE) {
  echo "<p class='alert alert-success'>New record created successfully</p>";
} else {
  echo "<p class='alert alert-danger'>Error: " . $sql . "<br>" . $conn->error . "</p>";
}
echo "</div>";
echo "</div>";
echo "</div>";
echo "<div class='container'>";

$sql = "SELECT * FROM randuser";
$result = $conn->query($sql);

if ($result->num_rows>0){
    echo "<table class='table table-hover'>";
    echo "<thead>";
    echo "  <tr>";
    echo "    <th>First Name</th>";
    echo "    <th>Last Name</th>";
    echo "    <th>Country</th>";
    echo "  <tr>";
    echo "</thead>";
    echo "<tbody>";
    
    while($row = $result->fetch_assoc()){
        echo "  <tr>";
        echo "    <td>" . $row['firstname'] . "</td>";
        echo "    <td>" . $row['lastname'] . "</td>";
        echo "    <td>" . $row['country'] . "</td>";
        echo "  </tr>";
    }
} else {
    echo "0 results";
}

$conn->close();

?>

    <br><br>
    <button onclick="history.back()">Back</button>
<br>

<script src="app.js"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
<script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>

</body>
<footer>Bootstrap was used to style fonts, tables, and alerts.</footer>
</html>