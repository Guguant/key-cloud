$(document).ready(function() {
    // 页面加载完毕
    // 执行run_monitorist()，获取已经监控的设备列表
    run_monitorist();

    // URL: /configure.shtml/monitorlist.txt
    $("#ismonitoring").click(function() {
        $("#MonitorList").empty();
        run_monitorist();
    });

    // run_monitorist function
    function run_monitorist() {
        $.ajax({
            type: 'GET',
            url: '/api/monitorlist.json',
            dataType: 'json',
            success: function(json) {
                var item = "";
                var count = 1;
                $.each(json, function(i, index) {
                    item = "";
                    item += '<tr>' +
                        '<th scope="row">' + (count++).toString() +
                        '<td>' + index.sroomId +
                        '<td>' + index.sPosition +
                        '<td>' + index.sIP +
                        '<td>' + index.sPort +
                        '<td class="text-center">';
                    if (index.sFacus == 1)
                        item += '<i class="text-danger fa fa-heart" aria-hidden="true"></i> ';
                    else
                        item += '<i class="fa fa-heart-o" aria-hidden="true"></i> ';
                    /*
                    '<i class="fa fa-pencil-square-o" aria-hidden="true"></i> ' +
                    '<i class="fa fa-times" aria-hidden="true"></i>' +
                    */
                    item += '</tr>';
                    $("#MonitorList").append(item);
                });
            }
        });
    }
});