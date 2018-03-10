$(document).ready(function() {

    // URL: /index.html/
    //      Get the status of sensors.
    //      fix timer = 1000ms timer.
    setInterval(function() {
        $.ajax({
            type: 'GET',
            url: '/api/log.json',
            dataType: 'json',
            success: function(json) {
                // 实时状态列表
                $("#log").empty();
                var item = "";
                var item_index = 1;
                $.each(json, function(i, index) {;
                    item = "";
                    item += '<li class="list-group-item">' +
                        '<span class="badge badge-pill badge-dark">' + (item_index++).toString() + '</span>' +
                        ' <span class=" font-weight-bold">' + index.time + '</span>' +
                        '<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' + index.info +
                        '</li>';
                    $("#log").append(item);
                });
                // sum: 记录的总数量
                $("#sum").empty().text(item_index - 1);
            }
        });
    }, 1000);
});