<?php
/**
 * Base template - Common header
 *
 * @package    HNG2
 * @subpackage core
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 *             
 * @var template $template
 * @var settings $settings
 * @var config   $config
 * @var account  $account
 */

use hng2_base\account;
use hng2_base\config;
use hng2_base\settings;
use hng2_base\template;

$favicon = $template->get("favicon");
if( empty($favicon) ) $favicon = "{$template->url}/media/favicon.ico";
?>

<!-- Base metas -->
<meta name="viewport"              content="width=device-width, initial-scale=1">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta http-equiv="Content-Type"    content="text/html; charset=utf-8">
<!--suppress CssInvalidPropertyValue -->
<style type="text/css">@-ms-viewport{ width: device-width; }</style>
<meta charset="UTF-8">

<title><?= $template->get_page_title() ?></title>
<meta name="description"   content="<?= $settings->get("engine.meta_description") ?>">
<meta name="keywords"      content="<?= $settings->get("engine.meta_keywords") ?>">
<meta name="rating"        content="<?= $settings->get("engine.meta_rating") == "" ? "general" : $settings->get("engine.meta_rating") ?>">
<meta name="revisit-after" content="<?= $settings->get("engine.meta_revisit_after") == "" ? "7 days" : $settings->get("engine.meta_revisit_after") ?>">
<? if( $settings->get("engine.meta_robots") != "" ): ?>
    <meta name="robots" content="<?= $settings->get("engine.meta_robots") ?>">
<? endif ?>

<link rel="icon"          type="image/x-icon" href="<?= $favicon ?>">
<link rel="shortcut icon" type="image/x-icon" href="<?= $favicon ?>">

<!-- Defaults -->
<script type="text/javascript">
    var $_FULL_ROOT_PATH          = '<?= $config->full_root_path ?>';
    var $_COOKIES_DOMAIN          = '<?= $config->cookies_domain ?>';
    var $_PHP_SELF                = '<?= $_SERVER["PHP_SELF"] ?>';
    var $_REQUEST_URI             = '<?= $_SERVER["REQUEST_URI"] ?>';
    var $_CURRENT_USER_ID_ACCOUNT = '<?= $account->id_account ?>';
    var $_CURRENT_USER_LANGUAGE   = '<?= $_COOKIE[$config->language_cookie_var] ?>';
    var $_CURRENT_USER_LEVEL      = parseInt('<?= $account->level ?>');
    var $_CURRENT_USER_IS_ADMIN   = <?= $account->_is_admin ? "true" : "false" ?>;
    var $_CURRENT_USER_IS_MOD     = <?= $account->level >= config::MODERATOR_USER_LEVEL ? "true" : "false" ?>;
    var $_TEMPLATE_URL            = '<?= $template->url ?>';
    var $_SCRIPTS_VERSION         = '<?= $config->scripts_version ?>';
    var $_IS_MOBILE               = <?= is_mobile() ? "true" : "false" ?>;
    var $_GENERIC_CONFIRMATION    = '<?= $language->confirm_action ?>';
    var $_SILENT_NOTIFICATIONS    = '<?= $account->engine_prefs["!core:silent_notifications"] ?>' == 'true';
    
    var $_MAIN_MENU_AUTO_COLLAPSE_WIDTH = parseInt('<?= (int) $settings->get("engine.main_menu_auto_collapse_width", 700) ?>');
    
    var tinymce_full_toolbar     = 'bold italic underline strikethrough | forecolor backcolor | styleselect fontsizeselect removeformat | undo redo | '
                                 + 'blockquote alignleft aligncenter alignright alignjustify | outdent indent bullist numlist | hr link unlink anchor ';
    
    var tinymce_standard_toolbar = 'bold italic underline strikethrough | forecolor backcolor | fontsizeselect removeformat | '
                                 + 'blockquote outdent indent | hr link unlink';
    
    var tinymce_minimal_toolbar  = 'bold italic underline strikethrough | forecolor backcolor removeformat | hr link unlink';
    
    var tinymce_default_css_files = [
        $_FULL_ROOT_PATH  + '/media/styles~v' + $_SCRIPTS_VERSION + '.css',
        $_TEMPLATE_URL    + '/media/styles~v' + $_SCRIPTS_VERSION + '.css',
        $_TEMPLATE_URL    + '/media/post_styles~v' + $_SCRIPTS_VERSION + '.css'
    ];
    var tinymce_custom_plugins = [];
    var tinymce_custom_toolbar_buttons = [];
</script>
<script type="text/javascript" src="<?= $config->full_root_path ?>/media/defaults~v<?=$config->engine_version?>.js"></script>

<!-- jQuery -->
<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/jquery-1.11.0.min.js"></script>
<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/jquery-migrate-1.2.1.js"></script>
<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/jquery.cookie.js"></script>
<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/jquery.scrollTo.js"></script>

<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/clipboard.js"></script>
<script type="text/javascript">
    var $_CLIPBOARD_COPIED = '<?= addslashes($language->clipboard->copied) ?>';
    var $_CLIPBOARD_UNABLE = '<?= addslashes($language->clipboard->unable_to_copy) ?>';
    $(document).ready(function()
    {
        var clipboard = new Clipboard('.clipboard-copy');
        
        clipboard.on('success', function(e) { alert($_CLIPBOARD_COPIED); });
        
        clipboard.on('error', function(e) {
            var text = e.text; if( ! text ) text = $(e.trigger).attr('data-clipboard-text');
            prompt($_CLIPBOARD_UNABLE, text);
        });
    });
</script>

<!-- jQuery UI -->
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/jquery-ui-1.10.4.custom.min.js"></script>
<link rel="stylesheet" type="text/css" href="<?= $config->full_root_path ?>/lib/jquery-ui-themes-1.10.4/blitzer/jquery-ui.css">
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/jquery.ui.touch-punch.min.js"></script>

<!-- UI Additions -->
<link rel="stylesheet" type="text/css" href="<?= $config->full_root_path ?>/lib/font-awesome-4.6.3/css/font-awesome.css">
<link rel="stylesheet" type="text/css" href="<?= $config->full_root_path ?>/lib/emojione-2.2.5/css/emojione-awesome.css">
<link rel="stylesheet" type="text/css" href="<?= $config->full_root_path ?>/lib/prettyPhoto_compressed_3.1.6/css/prettyPhoto.css">
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/prettyPhoto_compressed_3.1.6/js/jquery.prettyPhoto.js"></script>
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/sprintf.js"></script>
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/ion.sound-3.0.7/js/ion.sound.min.js"></script>
<script type="text/javascript"          src="<?= $config->full_root_path ?>/lib/jquery.lazyload.js"></script>
<script type="text/javascript"> $(document).ready(function() { $('.prettyPhoto').prettyPhoto({social_tools: false}); }); </script>
<script type="text/javascript"> $(document).ready(function() { $('.lazyload').lazyload({effect: 'fadeIn', failure_limit : 99999}); }); </script>