$(document).ready(function() {
    $(document).on('submit', '#settings_form', function() {
        var data = {};
        $('#settings_form [name]').each(function(index, el) {
            data[$(el).attr('name')] = $(el).val();
        });

        $('#result').text('');
        $.ajax({
            url: '/save',
            method: 'Post',
            dataType: 'html',
            data: data,
            success: function(data) {
                $('#result').text('订阅成功').show().fadeOut(3000);
            },
            error: function(data) {
                $('#result').text('订阅失败.').show().fadeOut(3000);
            }
        });
        return false;
    });
});