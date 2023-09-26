<?php
if(isset($_GET['ALERTA']) && $_GET['ALERTA'] == 1) {
    echo "ALERTA";
} else {
    echo "NO HAY ALERTAS";
}
?>



// Código JavaScript
function enviarValor(valor) {
  // Realizar una solicitud GET utilizando fetch
  fetch('tu_url?valor=' + encodeURIComponent(valor))
    .then(response => response.text())
    .then(data => {
      // Manejar la respuesta recibida
      console.log(data);
    })
    .catch(error => {
      // Manejar errores
      console.error(error);
    });
}

// Llamar a la función para enviar el valor
enviarValor('mi_valor');



<!DOCTYPE html>
<html>
<head>
  <title>Mostrar señal recibida</title>
</head>
<body>
  <h1>Mostrar señal recibida</h1>
  <p id="señal"></p>

  <script>
    function mostrarSeñal() {
      // Realizar una solicitud GET utilizando fetch o XMLHttpRequest
      fetch('tu_url')
        .then(response => response.text())
        .then(data => {
          // Mostrar la señal recibida en la etiqueta HTML
          document.getElementById('señal').textContent = data;
        })
        .catch(error => {
          // Manejar errores
          console.error(error);
        });
    }

    // Llamar a la función para mostrar la señal recibida
    mostrarSeñal();
  </script>
</body>
</html>

