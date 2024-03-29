<?php
/**
 * @file
 * Image module integration.
 */

/**
 * Implements hook_filefield_paths_field_type_info() for image.module.
 */
function image_filefield_paths_field_type_info() {
  return array('image');
}

/**
 * Implements hook_menu_alter().
 */
function filefield_paths_menu_alter(array &$items) {
  // Workaround for issue with 'temporary://' image styles not being generated
  // correctly in Drupal core Image module.
  // @see https://www.drupal.org/node/2560139
  if (!isset($items['system/temporary/styles/%image_style']) && isset($items['system/files/styles/%image_style'])) {
    $items['system/temporary/styles/%image_style'] = $items['system/files/styles/%image_style'];
  }
}
