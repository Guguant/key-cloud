$(document).ready(function() {

    // URL: /index.html/
    //      Get the status of sensors.
    //      fix timer = 1000ms timer.
    setInterval(function() {
        $.ajax({
            type: 'GET',
            url: '/real-status.json',
            dataType: 'json',
            success: function(json) {
                var on_index = 1;
                var off_index = 1;
                var wrong_index = 1;

                // 关注列表
                $("#on-facus").empty();
                $("#off-facus").empty();
                $("#wrong-facus").empty();

                // 实时状态列表
                $("#on-status").empty();
                $("#off-status").empty();
                $("#wrong-status").empty();

                var item = "";
                $.each(json, function(i, index) {
                    item = "";
                    if (index.sOpen == "on") {
                        if (index.sFacus == "1") {
                            $("#on-facus").append('<span class="badge badge-success">' + index.sroomId + '</span> ');
                        }
                        item += '<tr style="background:#669966;color:black">' +
                            '<th scope="row">' + (on_index++).toString() +
                            '<td>' + index.sPosition + ' ' + index.sroomId +
                            '<td>' + index.sOpen +
                            '<td>' + index.sIP + ':' + index.sPort +
                            '</tr>';
                        $("#on-status").append(item);
                    } else if (index.sOpen == "off") { // Open status : off.
                        if (index.sFacus == "1") {
                            $("#off-facus").append('<span class="badge badge-light">' + index.sroomId + '</span> ');
                        }
                        item += '<tr style="background:#CCCCCC;color:black">' +
                            '<th scope="row">' + (off_index++).toString() +
                            '<td>' + index.sPosition + ' ' + index.sroomId +
                            '<td>' + index.sOpen +
                            '<td>' + index.sIP + ':' + index.sPort +
                            '</tr>';
                        $("#off-status").append(item);
                    } else {
                        if (index.sFacus == "1") {
                            $("#wrong-facus").append('<span class="badge badge-danger">' + index.sroomId + '</span> ');
                        }
                        item += '<tr style="background:#CC3333;color:black">' +
                            '<th scope="row">' + (wrong_index++).toString() +
                            '<td>' + index.sPosition + ' ' + index.sroomId +
                            '<td>' + index.sOpen +
                            '<td>' + index.sIP + ':' + index.sPort +
                            '</tr>';
                        $("#wrong-status").append(item);
                    }
                });

                // sum: 传感器的总数量
                // on : 状态为on, 传感器的数量
                // off: 状态为off, 传感器的数量
                $("#sum").text(on_index + off_index + wrong_index - 3);
                $("#on").text(on_index - 1);
                $("#off").text(off_index - 1);
                $("#wrong").text(wrong_index - 1);
            }
        });
    }, 1000);
});