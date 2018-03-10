$(document).ready(function() {
    // 新增设备
    // URL: POST /configure.shtml/addLock.txt
    $("#AddDeviceForm").submit(function() {
        var facus = "1";
        if ($('input[name=facus]').is(':checked')) {
            facus = "1";
        } else {
            facus = "0";
        }
        var formData = {
            'roomid': $('input[name=roomid]').val(),
            'position': $('input[name=position]').val(),
            'IP': $('input[name=IP]').val(),
            'port': $('input[name=port]').val(),
            'facus': facus
        };

        $.ajax({
            type: "POST",
            url: "/api/addDeviceInfo.json",
            dataType: 'json',
            data: formData,
        })

        .done(function(backdata) {
            // DEBUG
            alert(backdata["success"]);
            if (backdata["success"] == 1) {
                out = '<div class = "alert alert-success">' +
                    '<strong>新增成功</strong>' +
                    '</div>';
                $("#out").empty().append(out);
            } else {
                out = '<div class = "alert alert-danger">' +
                    '<strong>新增失败</strong>' +
                    '</div>';
                $("#out").empty().append(out);
            }
        });
        event.preventDefault();
    });
});