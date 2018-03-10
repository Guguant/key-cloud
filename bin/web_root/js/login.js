$(document).ready(function() {
    // URL: /index.html/
    //     login page js
    ///>  TODO
    // login, username and passwd checking

    $("#loginform").submit(function(event) {
        var loginFormData = {
            'username': $('input[name=username]').val(),
            'passwd': $('input[name=passwd]').val(),
        };

        $.ajax({
            type: 'POST',
            url: '/api/login.json',
            dataType: 'json',
            data: loginFormData,
        })

        .done(function(backdata) {
            if (backdata["success"] == 1) {
                out = "<div class =\"alert alert-success\"> \
                            <strong>登录成功</strong> \
                            </div>";
                $("#out").empty().append(out);
                location.href = "/src/status.shtml";
            } else {
                out = "<div class =\"alert alert-danger\"> \
                    <strong>用户名或密码错误</strong> \
                    </div>";
                $("#out").empty().append(out);
            }
        });
        event.preventDefault();
    });
});