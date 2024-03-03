<?php
/**
 * @file
 * Hooks provided by the File (Field) Paths module.
 */

/**
 * Define field(s) to be displayed on the File (Field) Paths settings form and
 * used during the processing of uploaded files.
 *
 * @param array $field
 *   The field definition this File (Field) Paths settings field applies to.
 * @param array $instance
 *   The field instance this File (Field) Paths settings field applies to.
 *
 * @return array
 *   An array whose keys are field names and whose values are arrays defining
 *   the field, with the following key/value pairs:
 *   - title: The title fo the field.
 *   - form: A keyed array of Form API elements.
 *
 * @see hook_filefield_paths_process_file()
 */
function hook_filefield_paths_field_settings(array $field, array $instance) {
  return array(
    'file_path' => array(
      'title' => 'File path',
      'form'  => array(
        'value' => array(
          '#type'             => 'textfield',
          '#title'            => t('File path'),
          '#maxlength'        => 512,
          '#size'             => 128,
          '#element_validate' => array('_file_generic_settings_file_directory_validate'),
          '#default_value'    => $instance['settings']['file_directory'],
        ),
      ),
    ),
  );
}

/**
 * Declare a compatible field type for use with File (Field) Paths.
 *
 * @return array
 */
function hook_filefield_paths_field_type_info() {
  return array('file');
}

/**
 * Process the uploaded files.
 *
 * @param string $type
 *   The entity type containing the files for processing.
 * @param object $entity
 *   The entity containing the files for processing.
 * @param array $field
 *   The definition of the field containing the files for processing.
 * @param array $instance
 *   The instance of the field containing the files for processing.
 * @param string $langcode
 *   The language code of the field containing the files for processing.
 * @param array $items
 *   A pass-by-reference array of all the files for processing.
 *
 * @see filefield_paths_filefield_paths_process_file()
 */
function hook_filefield_paths_process_file($type, $entity, array $field, array $instance, $langcode, array &$items) {
}
