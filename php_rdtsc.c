/* This code was generated by phptoc.c */
/* {{{ Includes */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_rdtsc.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend.h"
#include "zend_API.h"
#include "zend_exceptions.h"
#include "zend_operators.h"
#include "zend_constants.h"
#include "zend_ini.h"
#include "zend_interfaces.h"

#ifndef HAVE_TICK_COUNTER
#error your platform is not supported
#endif

#define RDTSC_RETURN_LONG_LONG(__val) \
{ \
          if ((__val) < LONG_MAX) {               \
                  RETURN_LONG((long) (__val));            \
          } else {                                \
                  char *ret;                      \
                  int l = spprintf(&ret, 0, "%llu", (__val));    \
                  RETURN_STRINGL(ret, l, 0);              \
          }                                       \
 }

/* }}} */
/* {{{ Class entry pointers */
PHPAPI zend_class_entry *rdtsc_Rdtsc_ptr;

/* }}} */
/* {{{ Methods for class Rdtsc */

// public static function getticks()
ZEND_METHOD(Rdtsc, getticks)
{
  if (zend_parse_parameters_none() == FAILURE) {
      return;
  }

  RDTSC_RETURN_LONG_LONG(getticks());
}

/* }}} */
/* {{{ Global functions */

/* }}} */
/* {{{ Method tables for classes */

ZEND_BEGIN_ARG_INFO_EX(arginfo_rdtsc_Rdtsc_getticks, 0, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry rdtsc_Rdtsc_functions[] = {
  ZEND_ME(Rdtsc,               getticks,                      arginfo_rdtsc_Rdtsc_getticks,                      ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

/* }}} */
/* {{{ Function table */

static zend_function_entry rdtsc_functions[] = {
  {NULL, NULL, NULL}
};

/* }}} */
/* {{{ Init */

PHP_MINIT_FUNCTION(rdtsc)
{
  zend_class_entry _ce;
  
  INIT_CLASS_ENTRY(_ce, "Rdtsc", rdtsc_Rdtsc_functions);
  rdtsc_Rdtsc_ptr = zend_register_internal_class(&_ce TSRMLS_CC);

  return SUCCESS;
}

/* }}} */
/* {{{ Info */

PHP_MINFO_FUNCTION(rdtsc)
{
  php_info_print_table_start();
  php_info_print_table_header(2, "rdtsc", "enabled");
  php_info_print_table_row(2, "Version", "0.1");
  php_info_print_table_end();
}

/* }}} */
/* {{{ Module entry */

zend_module_entry rdtsc_module_entry = {
  STANDARD_MODULE_HEADER,
  "rdtsc",
  rdtsc_functions,
  PHP_MINIT(rdtsc),
  NULL,
  NULL,
  NULL,
  PHP_MINFO(rdtsc),
  "0.1",
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_RDTSC
ZEND_GET_MODULE(rdtsc)
#endif
/* }}} */