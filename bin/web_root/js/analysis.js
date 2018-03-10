$(document).ready(function() {
    runGetSensorDataTable();
    // This code snippet is to get
    // all sensor data, then generate a table.
    function runGetSensorDataTable() {
        $.ajax({
            type: 'GET',
            url: '/api/analysis/result.json',
            dataType: 'json',
            success: function(json) {
                var table_title = json["title"];
                var table_time = json["time"];

                $("#device-on").empty();
                $("#device-off").empty();
                $("#device-wrong").empty();

                var table_data_status_count = {
                    "on": 0,
                    "off": 0,
                    "wrong": 0
                };
                //////////////////////////////////////////////
                /// 【表格】
                ///     标题, 时间
                $("#title").empty().append(table_title);
                $("#time").empty().append(table_time);

                /// 【表格】
                ///     内容
                data = json["data"][0];
                // 先分析开关状态，在分析楼层
                for (var i = 0; i < data.length; ++i) {
                    if (data[i].sOpen == "on") {
                        $("#device-on").append(data[i].sroomId + '&nbsp;&nbsp;&nbsp');
                        table_data_status_count["on"]++;
                    } else if (data[i].sOpen == "off") {
                        $("#device-off").append(data[i].sroomId + '&nbsp;&nbsp;&nbsp');
                        table_data_status_count["off"]++;
                    } else if (data[i].sOpen == "wrong") {
                        $("#device-wrong").append(data[i].sroomId + '&nbsp;&nbsp;&nbsp');
                        table_data_status_count["wrong"]++;
                    } else {}
                }
                ////////////////////////////////////////////
                // 数据统计
                var allSum = table_data_status_count["on"] + table_data_status_count["off"] +
                    table_data_status_count["wrong"];
                $("#allsum").empty().append(allSum);
                $("#onsum").empty().append(table_data_status_count["on"]);
                $("#offsum").empty().append(table_data_status_count["off"]);
                $("#wrongsum").empty().append(table_data_status_count["wrong"]);

                // 展示数据图表
                showPie(table_data_status_count);
            }
        });
    };

    // 数据饼状图
    function showPie(json) {
        // Radialize the colors
        Highcharts.setOptions({
            colors: Highcharts.map(Highcharts.getOptions().colors, function(color) {
                return {
                    radialGradient: {
                        cx: 0.5,
                        cy: 0.3,
                        r: 0.7
                    },
                    stops: [
                        [0, color],
                        [1, Highcharts.Color(color).brighten(-0.3).get('rgb')] // darken
                    ]
                };
            })
        });

        // Build the chart
        Highcharts.chart('pieShow', {
            chart: {
                plotBackgroundColor: '#333333',
                plotBorderWidth: null,
                plotShadow: false,
                type: 'pie',
                margin: 0
            },
            title: {
                text: null
            },
            credits: {
                enabled: false
            },
            tooltip: {
                borderRadius: 10,
                borderWidth: 3,
                animation: true,
                pointFormat: '<b>{point.percentage:.1f}%</b>'
            },
            legend: {
                symbolRadius: 2,
                itemStyle: { cursor: 'pointer', color: '#FFFFFF' },
                color: '#FFFFFF',
                align: 'center', //程度标的目标地位
                verticalAlign: 'top', //垂直标的目标地位
                x: 0,
                y: 0
            },
            plotOptions: {
                pie: {
                    allowPointSelect: true,
                    cursor: 'pointer',
                    dataLabels: {
                        enabled: true,
                        format: '<b>{point.name}</b>: {point.percentage:.1f} %',
                        style: {
                            color: (Highcharts.theme && Highcharts.theme.contrastTextColor) || 'white'
                        }
                    },
                    showInLegend: true // 显示在图例中
                }
            },
            colors: ['#99CC66', '#FFFFFF', '#CC3333'],
            series: [{
                name: 'status',
                data: [{
                        name: '开',
                        y: json["on"],
                        sliced: true,
                        selected: true
                    },
                    { name: '关', y: json["off"] },
                    { name: '异常', y: json["wrong"] }
                ]
            }]
        });
    }
});