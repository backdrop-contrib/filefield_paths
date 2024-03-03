<?php
/**
 * @file
 *
 * Administration functions for the File (Field) Paths module.
 */

/**
 * Settings form callback.
 */
function filefield_paths_settings_form(array $form, array $form_state) {
  $form['#config'] = 'filefield_paths.settings';
  $temp_location = config_get('filefield_paths.settings', 'filefield_paths_temp_location');
  if (empty($temp_location)) {
    $temp_location = filefield_paths_recommended_temporary_scheme() . 'filefield_paths';
  }
  $form['filefield_paths_temp_location'] = array(
    '#title'            => t('Temporary file location'),
    '#type'             => 'textfield',
    '#default_value'    => $temp_location,
    '#description'      => t('The location that unprocessed files will be uploaded prior to being processed by File (Field) Paths.<br />It is recommended that you use the temporary file system (temporary://), or, as a 2nd choice, the private file system (private://) if your server configuration allows for one of those.<br /><strong>Never use the public directory (public://) if the site supports private files, or private files can be temporarily exposed publicly.</strong>'),
    '#element_validate' => array('filefield_paths_settings_form_temp_location_validate'),
  );

  return system_settings_form($form);
}

/**
 * Validation callback for 'Temporary file location' setting.
 */
function filefield_paths_settings_form_temp_location_validate(array $element, array $form_state) {
  $scheme = file_uri_scheme($element['#value']);
  if (!$scheme) {
    form_error($element, t('Invalid file location. You must include a file stream wrapper (e.g., public://).'));
    return FALSE;
  }

  if (!file_stream_wrapper_valid_scheme($scheme)) {
    form_error($element, t('Invalid file stream wrapper.'));
    return FALSE;
  }

  if ((!is_dir($element['#value']) || !is_writable($element['#value'])) && !file_prepare_directory($element['#value'], FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    form_error($element, t('File location can not be created or is not writable.'));
    return FALSE;
  }
}
