<?
/**
 * Base template - Embedded layout
 *
 * @package    HNG2
 * @subpackage core
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 */

use hng2_tools\internals;

$template->init(__FILE__);
$account->ping();

foreach($template->get_includes("pre_rendering") as $module => $include)
{
    $this_module = $modules[$module];
    include "{$this_module->abspath}/contents/{$include}";
}

header("Content-Type: text/html; charset=utf-8"); ?>
<!DOCTYPE html>
<html>
<head>
    <!--suppress CssInvalidPropertyValue -->
    <style type="text/css">@-ms-viewport{ width: device-width; }</style>
    <meta name="viewport"              content="width=device-width, initial-scale=1">
    <? $template->set("include_notification_functions", false); ?>
    <? $template->set("jquery_ui_theme", "cupertino"); ?>
    <? include ROOTPATH . "/includes/common_header.inc" ?>
    
    <!-- This template -->
    <? $css_version = "1.0.4-1"; ?>
    <link rel="stylesheet" type="text/css" href="<?= $template->url ?>/media/styles~v<?= $css_version ?>.css">
    <link rel="stylesheet" type="text/css" href="<?= $template->url ?>/media/post_styles~v<?= $css_version ?>.css">
    <link rel="stylesheet" type="text/css" href="<?= $template->url ?>/media/colors~v<?= $css_version ?>.css">
    
    <!-- Always-on -->
    <? $template->render_always_on_files(); ?>
    
    <!-- Per module loads -->
    <?
    foreach($template->get_includes("html_head") as $module => $include)
    {
        $this_module = $modules[$module];
        include "{$this_module->abspath}/contents/{$include}";
    }
    ?>
</head>
<body data-orientation="landscape" data-viewport-class="0" <?=$template->get("additional_body_attributes")?>  class="popup"
      data-is-known-user="<?= $account->_exists ? "true" : "false" ?>"
      data-user-level="<?= $account->level ?>">

<div id="body_wrapper">
    
    <div id="content">
        <? include "{$current_module->abspath}/contents/{$template->page_contents_include}"; ?>
    </div><!-- /#content -->
    
    <?
    foreach($template->get_includes("post_footer") as $module => $include)
    {
        $this_module = $modules[$module];
        include "{$this_module->abspath}/contents/{$include}";
    }
    ?>
    
</div><!-- /#body_wrapper -->

<!-- These must be at the end of the document -->
<script type="text/javascript" src="<?= $config->full_root_path ?>/lib/tinymce-4.6.3/tinymce.min.js"></script>
<? $template->render_tinymce_additions(); ?>
<script type="text/javascript" src="<?= $config->full_root_path ?>/media/init_tinymce~v<?=$config->engine_version?>.js"></script>
<script type="text/javascript">
    $(document).ready(function()
    {
        tinymce.init(tinymce_defaults);
        tinymce.init(tinymce_full_defaults);
        tinymce.init(tinymce_minimal_defaults);
    });
</script>

<? internals::render(__FILE__); ?>

</body>
</html>
