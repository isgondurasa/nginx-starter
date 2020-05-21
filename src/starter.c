
/**
 * (c) BSD-2-Cause, link: https://opensource.org/licenses/BSD-2-Clause
 * (c) A. Sviridov, mailto: isgondurasa@gmail.com
 */

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include <nginx.h>

static char *ngx_http_starter(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static ngx_int_t ngx_http_starter_handler(ngx_http_request_t *r);


static ngx_command_t ngx_http_starter_commands[] = {
	{ ngx_string("handle_requests"),
	  NGX_HTTP_LOC_CONF|NGX_CONF_NOARGS,
	  ngx_http_starter,
	  NGX_HTTP_LOC_CONF_OFFSET,
	  0,
	  NULL },
	

	ngx_null_command  /* terminate command */
};

static char *
ngx_http_starter(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {

	// install handler
	ngx_http_core_loc_conf_t *clcf;
	clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
	clcf->handler = ngx_http_starter_handler;

	return NGX_CONF_OK;
}

static ngx_int_t
ngx_http_starter_handler(ngx_http_request_t *r)
{
	return NGX_DONE;
}


ngx_http_module_t
ngx_http_starter_module_ctx = {
    NULL,                                  /* preconfiguration */
    NULL,                                  /* postconfiguration */

    NULL,                                  /* create main configuration */
    NULL,                                  /* init main configuration */

    NULL,                                  /* create server configuration */
    NULL,                                  /* merge server configuration */

    NULL,                                  /* create location configuration */
    NULL,                                  /* merge location configuration */
};

ngx_module_t
ngx_http_starter_module = {
	NGX_MODULE_V1,
	&ngx_http_starter_module_ctx, /* module context*/
	ngx_http_starter_commands,    /* command context */
	NGX_HTTP_MODULE,
	NULL,                                  /* init master */
	NULL,                                  /* init module */
	NULL,                                  /* init process */
	NULL,                                  /* init thread */
	NULL,                                  /* exit thread */
	NULL,                                  /* exit process */
	NULL,                                  /* exit master */
	NGX_MODULE_V1_PADDING,
};
