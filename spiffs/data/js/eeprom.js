$(document).ready(function(){
  $.ajax({
    type:     'GET',
    url:      'eeprom',
    dataType: 'json',
    success:  function (data) {
                for (var category in data) {
                  for (var key in data[category]) {
                    $('#'+category+'-'+key).val(data[category][key]);
                  }
                }
              },
    error:    function (xhRequest, textStatus, errorThrown) {
                alert(textStatus + " : " + errorThrown);
              }
  });
});
