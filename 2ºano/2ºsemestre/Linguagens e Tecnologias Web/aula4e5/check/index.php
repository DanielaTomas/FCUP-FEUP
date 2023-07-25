<?php
  $db = new PDO('sqlite:example.db'); 

  $prep = $db->prepare('SELECT id, name FROM names');
  $prep->execute(array());
  $rows = $prep->fetchAll();

  echo "<table>";
  foreach($rows as $row)
    echo "<tr><td>".$row['id']."</td><td>".$row['name']."</td></tr>";
  echo "</table>";
?>
