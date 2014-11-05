// Auto generated 2014-10-31 16:49:07.634262
#include "neovim.h"
#include "neovimconnector.h"
#include "neovimrequest.h"

namespace NeovimQt {

Neovim::Neovim(NeovimConnector *c)
:m_c(c)
{
}

// Slots
void Neovim::window_get_buffer(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_buffer", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_BUFFER);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_get_cursor(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_cursor", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_CURSOR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_set_cursor(int64_t window, QPoint pos)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_set_cursor", 2);
	r->setFunction(Function::NEOVIM_FN_WINDOW_SET_CURSOR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(pos);
}
void Neovim::window_get_height(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_height", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_HEIGHT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_set_height(int64_t window, int64_t height)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_set_height", 2);
	r->setFunction(Function::NEOVIM_FN_WINDOW_SET_HEIGHT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(height);
}
void Neovim::window_get_width(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_width", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_WIDTH);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_set_width(int64_t window, int64_t width)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_set_width", 2);
	r->setFunction(Function::NEOVIM_FN_WINDOW_SET_WIDTH);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(width);
}
void Neovim::window_get_var(int64_t window, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_var", 2);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(name);
}
void Neovim::window_set_var(int64_t window, QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_set_var", 3);
	r->setFunction(Function::NEOVIM_FN_WINDOW_SET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::window_get_option(int64_t window, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_option", 2);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(name);
}
void Neovim::window_set_option(int64_t window, QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_set_option", 3);
	r->setFunction(Function::NEOVIM_FN_WINDOW_SET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::window_get_position(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_position", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_POSITION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_get_tabpage(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_get_tabpage", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_GET_TABPAGE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::window_is_valid(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("window_is_valid", 1);
	r->setFunction(Function::NEOVIM_FN_WINDOW_IS_VALID);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::vim_command(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_command", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_COMMAND);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_feedkeys(QByteArray keys, QByteArray mode)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_feedkeys", 2);
	r->setFunction(Function::NEOVIM_FN_VIM_FEEDKEYS);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(keys);
	m_c->send(mode);
}
void Neovim::vim_input(QByteArray keys)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_input", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_INPUT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(keys);
}
void Neovim::vim_replace_termcodes(QByteArray str, bool from_part, bool do_lt, bool special)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_replace_termcodes", 4);
	r->setFunction(Function::NEOVIM_FN_VIM_REPLACE_TERMCODES);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
	m_c->send(from_part);
	m_c->send(do_lt);
	m_c->send(special);
}
void Neovim::vim_command_output(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_command_output", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_COMMAND_OUTPUT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_eval(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_eval", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_EVAL);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_strwidth(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_strwidth", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_STRWIDTH);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_list_runtime_paths()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_list_runtime_paths", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_LIST_RUNTIME_PATHS);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_change_directory(QByteArray dir)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_change_directory", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_CHANGE_DIRECTORY);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(dir);
}
void Neovim::vim_get_current_line()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_current_line", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_CURRENT_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_set_current_line(QByteArray line)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_current_line", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_CURRENT_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(line);
}
void Neovim::vim_del_current_line()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_del_current_line", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_DEL_CURRENT_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_get_var(QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_var", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(name);
}
void Neovim::vim_set_var(QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_var", 2);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::vim_get_vvar(QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_vvar", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_VVAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(name);
}
void Neovim::vim_get_option(QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_option", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(name);
}
void Neovim::vim_set_option(QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_option", 2);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::vim_out_write(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_out_write", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_OUT_WRITE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_err_write(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_err_write", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_ERR_WRITE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_report_error(QByteArray str)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_report_error", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_REPORT_ERROR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(str);
}
void Neovim::vim_get_buffers()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_buffers", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_BUFFERS);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_get_current_buffer()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_current_buffer", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_CURRENT_BUFFER);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_set_current_buffer(int64_t buffer)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_current_buffer", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_CURRENT_BUFFER);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
}
void Neovim::vim_get_windows()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_windows", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_WINDOWS);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_get_current_window()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_current_window", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_CURRENT_WINDOW);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_set_current_window(int64_t window)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_current_window", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_CURRENT_WINDOW);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(window);
}
void Neovim::vim_get_tabpages()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_tabpages", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_TABPAGES);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_get_current_tabpage()
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_get_current_tabpage", 0);
	r->setFunction(Function::NEOVIM_FN_VIM_GET_CURRENT_TABPAGE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
}
void Neovim::vim_set_current_tabpage(int64_t tabpage)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_set_current_tabpage", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_SET_CURRENT_TABPAGE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
}
void Neovim::vim_subscribe(QByteArray event)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_subscribe", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_SUBSCRIBE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(event);
}
void Neovim::vim_unsubscribe(QByteArray event)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_unsubscribe", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_UNSUBSCRIBE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(event);
}
void Neovim::vim_register_provider(QByteArray feature)
{
	NeovimRequest *r = m_c->startRequestUnchecked("vim_register_provider", 1);
	r->setFunction(Function::NEOVIM_FN_VIM_REGISTER_PROVIDER);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(feature);
}
void Neovim::tabpage_get_windows(int64_t tabpage)
{
	NeovimRequest *r = m_c->startRequestUnchecked("tabpage_get_windows", 1);
	r->setFunction(Function::NEOVIM_FN_TABPAGE_GET_WINDOWS);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
}
void Neovim::tabpage_get_var(int64_t tabpage, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("tabpage_get_var", 2);
	r->setFunction(Function::NEOVIM_FN_TABPAGE_GET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
	m_c->send(name);
}
void Neovim::tabpage_set_var(int64_t tabpage, QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("tabpage_set_var", 3);
	r->setFunction(Function::NEOVIM_FN_TABPAGE_SET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::tabpage_get_window(int64_t tabpage)
{
	NeovimRequest *r = m_c->startRequestUnchecked("tabpage_get_window", 1);
	r->setFunction(Function::NEOVIM_FN_TABPAGE_GET_WINDOW);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
}
void Neovim::tabpage_is_valid(int64_t tabpage)
{
	NeovimRequest *r = m_c->startRequestUnchecked("tabpage_is_valid", 1);
	r->setFunction(Function::NEOVIM_FN_TABPAGE_IS_VALID);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(tabpage);
}
void Neovim::buffer_line_count(int64_t buffer)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_line_count", 1);
	r->setFunction(Function::NEOVIM_FN_BUFFER_LINE_COUNT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
}
void Neovim::buffer_get_line(int64_t buffer, int64_t index)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_line", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(index);
}
void Neovim::buffer_set_line(int64_t buffer, int64_t index, QByteArray line)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_set_line", 3);
	r->setFunction(Function::NEOVIM_FN_BUFFER_SET_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(index);
	m_c->send(line);
}
void Neovim::buffer_del_line(int64_t buffer, int64_t index)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_del_line", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_DEL_LINE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(index);
}
void Neovim::buffer_get_line_slice(int64_t buffer, int64_t start, int64_t end, bool include_start, bool include_end)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_line_slice", 5);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_LINE_SLICE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(start);
	m_c->send(end);
	m_c->send(include_start);
	m_c->send(include_end);
}
void Neovim::buffer_set_line_slice(int64_t buffer, int64_t start, int64_t end, bool include_start, bool include_end, QList<QByteArray> replacement)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_set_line_slice", 6);
	r->setFunction(Function::NEOVIM_FN_BUFFER_SET_LINE_SLICE);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(start);
	m_c->send(end);
	m_c->send(include_start);
	m_c->send(include_end);
	m_c->send(replacement);
}
void Neovim::buffer_get_var(int64_t buffer, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_var", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
}
void Neovim::buffer_set_var(int64_t buffer, QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_set_var", 3);
	r->setFunction(Function::NEOVIM_FN_BUFFER_SET_VAR);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::buffer_get_option(int64_t buffer, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_option", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
}
void Neovim::buffer_set_option(int64_t buffer, QByteArray name, QVariant value)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_set_option", 3);
	r->setFunction(Function::NEOVIM_FN_BUFFER_SET_OPTION);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
	m_c->send(value);
}
void Neovim::buffer_get_number(int64_t buffer)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_number", 1);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_NUMBER);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
}
void Neovim::buffer_get_name(int64_t buffer)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_name", 1);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_NAME);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
}
void Neovim::buffer_set_name(int64_t buffer, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_set_name", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_SET_NAME);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
}
void Neovim::buffer_is_valid(int64_t buffer)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_is_valid", 1);
	r->setFunction(Function::NEOVIM_FN_BUFFER_IS_VALID);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
}
void Neovim::buffer_insert(int64_t buffer, int64_t lnum, QList<QByteArray> lines)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_insert", 3);
	r->setFunction(Function::NEOVIM_FN_BUFFER_INSERT);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(lnum);
	m_c->send(lines);
}
void Neovim::buffer_get_mark(int64_t buffer, QByteArray name)
{
	NeovimRequest *r = m_c->startRequestUnchecked("buffer_get_mark", 2);
	r->setFunction(Function::NEOVIM_FN_BUFFER_GET_MARK);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	connect(r, &NeovimRequest::error, this, &Neovim::handleResponseError);
	m_c->send(buffer);
	m_c->send(name);
}

// Handlers

void Neovim::handleResponseError(uint32_t msgid, Function::FunctionId fun, const QString& msg, const msgpack_object& res)
{
	(void) msgid;
	QVariant errObj;
	if (decodeMsgpack(res, errObj)) {
		qWarning() << "Error while decoding error object as" << fun << res;
	}
	emit error(msg, errObj);
	switch(fun) {
	case Function::NEOVIM_FN_WINDOW_GET_BUFFER:
		emit err_window_get_buffer(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_CURSOR:
		emit err_window_get_cursor(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_SET_CURSOR:
		emit err_window_set_cursor(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_HEIGHT:
		emit err_window_get_height(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_SET_HEIGHT:
		emit err_window_set_height(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_WIDTH:
		emit err_window_get_width(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_SET_WIDTH:
		emit err_window_set_width(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_VAR:
		emit err_window_get_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_SET_VAR:
		emit err_window_set_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_OPTION:
		emit err_window_get_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_SET_OPTION:
		emit err_window_set_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_POSITION:
		emit err_window_get_position(msg, errObj);
		break;
	case Function::NEOVIM_FN_WINDOW_GET_TABPAGE:
		emit err_window_get_tabpage(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_COMMAND:
		emit err_vim_command(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_COMMAND_OUTPUT:
		emit err_vim_command_output(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_EVAL:
		emit err_vim_eval(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_STRWIDTH:
		emit err_vim_strwidth(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_CHANGE_DIRECTORY:
		emit err_vim_change_directory(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_LINE:
		emit err_vim_get_current_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_LINE:
		emit err_vim_set_current_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_DEL_CURRENT_LINE:
		emit err_vim_del_current_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_GET_VAR:
		emit err_vim_get_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_VAR:
		emit err_vim_set_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_GET_VVAR:
		emit err_vim_get_vvar(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_GET_OPTION:
		emit err_vim_get_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_OPTION:
		emit err_vim_set_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_BUFFER:
		emit err_vim_set_current_buffer(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_WINDOW:
		emit err_vim_set_current_window(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_TABPAGE:
		emit err_vim_set_current_tabpage(msg, errObj);
		break;
	case Function::NEOVIM_FN_VIM_REGISTER_PROVIDER:
		emit err_vim_register_provider(msg, errObj);
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOWS:
		emit err_tabpage_get_windows(msg, errObj);
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_VAR:
		emit err_tabpage_get_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_TABPAGE_SET_VAR:
		emit err_tabpage_set_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOW:
		emit err_tabpage_get_window(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_LINE_COUNT:
		emit err_buffer_line_count(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LINE:
		emit err_buffer_get_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_SET_LINE:
		emit err_buffer_set_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_DEL_LINE:
		emit err_buffer_del_line(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LINE_SLICE:
		emit err_buffer_get_line_slice(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_SET_LINE_SLICE:
		emit err_buffer_set_line_slice(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_VAR:
		emit err_buffer_get_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_SET_VAR:
		emit err_buffer_set_var(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_OPTION:
		emit err_buffer_get_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_SET_OPTION:
		emit err_buffer_set_option(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NUMBER:
		emit err_buffer_get_number(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NAME:
		emit err_buffer_get_name(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_SET_NAME:
		emit err_buffer_set_name(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_INSERT:
		emit err_buffer_insert(msg, errObj);
		break;
	case Function::NEOVIM_FN_BUFFER_GET_MARK:
		emit err_buffer_get_mark(msg, errObj);
		break;
	default:
		qWarning() << "Received error for function call that should not fail" << fun << msg;
	}
}

void Neovim::handleResponse(uint32_t msgid, Function::FunctionId fun, const msgpack_object& res)
{
	(void) msgid;
	switch(fun) {
	case Function::NEOVIM_FN_WINDOW_GET_BUFFER:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_buffer";
			} else {
				qDebug() << "window_get_buffer ->" << data;
				emit on_window_get_buffer(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_CURSOR:
		{
			QPoint data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_cursor";
			} else {
				qDebug() << "window_get_cursor ->" << data;
				emit on_window_get_cursor(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_CURSOR:
		{
			emit on_window_set_cursor();

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_HEIGHT:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_height";
			} else {
				qDebug() << "window_get_height ->" << data;
				emit on_window_get_height(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_HEIGHT:
		{
			emit on_window_set_height();

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_WIDTH:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_width";
			} else {
				qDebug() << "window_get_width ->" << data;
				emit on_window_get_width(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_WIDTH:
		{
			emit on_window_set_width();

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_var";
			} else {
				qDebug() << "window_get_var ->" << data;
				emit on_window_get_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_set_var";
			} else {
				qDebug() << "window_set_var ->" << data;
				emit on_window_set_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_OPTION:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_option";
			} else {
				qDebug() << "window_get_option ->" << data;
				emit on_window_get_option(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_OPTION:
		{
			emit on_window_set_option();

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_POSITION:
		{
			QPoint data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_position";
			} else {
				qDebug() << "window_get_position ->" << data;
				emit on_window_get_position(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_TABPAGE:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_get_tabpage";
			} else {
				qDebug() << "window_get_tabpage ->" << data;
				emit on_window_get_tabpage(data);
			}

		}
		break;
	case Function::NEOVIM_FN_WINDOW_IS_VALID:
		{
			bool data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal window_is_valid";
			} else {
				qDebug() << "window_is_valid ->" << data;
				emit on_window_is_valid(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_COMMAND:
		{
			emit on_vim_command();

		}
		break;
	case Function::NEOVIM_FN_VIM_FEEDKEYS:
		{
			emit on_vim_feedkeys();

		}
		break;
	case Function::NEOVIM_FN_VIM_INPUT:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_input";
			} else {
				qDebug() << "vim_input ->" << data;
				emit on_vim_input(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_REPLACE_TERMCODES:
		{
			QByteArray data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_replace_termcodes";
			} else {
				qDebug() << "vim_replace_termcodes ->" << data;
				emit on_vim_replace_termcodes(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_COMMAND_OUTPUT:
		{
			QByteArray data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_command_output";
			} else {
				qDebug() << "vim_command_output ->" << data;
				emit on_vim_command_output(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_EVAL:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_eval";
			} else {
				qDebug() << "vim_eval ->" << data;
				emit on_vim_eval(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_STRWIDTH:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_strwidth";
			} else {
				qDebug() << "vim_strwidth ->" << data;
				emit on_vim_strwidth(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_LIST_RUNTIME_PATHS:
		{
			QList<QByteArray> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_list_runtime_paths";
			} else {
				qDebug() << "vim_list_runtime_paths ->" << data;
				emit on_vim_list_runtime_paths(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_CHANGE_DIRECTORY:
		{
			emit on_vim_change_directory();

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_LINE:
		{
			QByteArray data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_current_line";
			} else {
				qDebug() << "vim_get_current_line ->" << data;
				emit on_vim_get_current_line(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_LINE:
		{
			emit on_vim_set_current_line();

		}
		break;
	case Function::NEOVIM_FN_VIM_DEL_CURRENT_LINE:
		{
			emit on_vim_del_current_line();

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_var";
			} else {
				qDebug() << "vim_get_var ->" << data;
				emit on_vim_get_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_set_var";
			} else {
				qDebug() << "vim_set_var ->" << data;
				emit on_vim_set_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_VVAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_vvar";
			} else {
				qDebug() << "vim_get_vvar ->" << data;
				emit on_vim_get_vvar(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_OPTION:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_option";
			} else {
				qDebug() << "vim_get_option ->" << data;
				emit on_vim_get_option(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_OPTION:
		{
			emit on_vim_set_option();

		}
		break;
	case Function::NEOVIM_FN_VIM_OUT_WRITE:
		{
			emit on_vim_out_write();

		}
		break;
	case Function::NEOVIM_FN_VIM_ERR_WRITE:
		{
			emit on_vim_err_write();

		}
		break;
	case Function::NEOVIM_FN_VIM_REPORT_ERROR:
		{
			emit on_vim_report_error();

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_BUFFERS:
		{
			QList<int64_t> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_buffers";
			} else {
				qDebug() << "vim_get_buffers ->" << data;
				emit on_vim_get_buffers(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_BUFFER:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_current_buffer";
			} else {
				qDebug() << "vim_get_current_buffer ->" << data;
				emit on_vim_get_current_buffer(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_BUFFER:
		{
			emit on_vim_set_current_buffer();

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_WINDOWS:
		{
			QList<int64_t> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_windows";
			} else {
				qDebug() << "vim_get_windows ->" << data;
				emit on_vim_get_windows(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_WINDOW:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_current_window";
			} else {
				qDebug() << "vim_get_current_window ->" << data;
				emit on_vim_get_current_window(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_WINDOW:
		{
			emit on_vim_set_current_window();

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_TABPAGES:
		{
			QList<int64_t> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_tabpages";
			} else {
				qDebug() << "vim_get_tabpages ->" << data;
				emit on_vim_get_tabpages(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_TABPAGE:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal vim_get_current_tabpage";
			} else {
				qDebug() << "vim_get_current_tabpage ->" << data;
				emit on_vim_get_current_tabpage(data);
			}

		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_TABPAGE:
		{
			emit on_vim_set_current_tabpage();

		}
		break;
	case Function::NEOVIM_FN_VIM_SUBSCRIBE:
		{
			emit on_vim_subscribe();

		}
		break;
	case Function::NEOVIM_FN_VIM_UNSUBSCRIBE:
		{
			emit on_vim_unsubscribe();

		}
		break;
	case Function::NEOVIM_FN_VIM_REGISTER_PROVIDER:
		{
			emit on_vim_register_provider();

		}
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOWS:
		{
			QList<int64_t> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal tabpage_get_windows";
			} else {
				qDebug() << "tabpage_get_windows ->" << data;
				emit on_tabpage_get_windows(data);
			}

		}
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal tabpage_get_var";
			} else {
				qDebug() << "tabpage_get_var ->" << data;
				emit on_tabpage_get_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_TABPAGE_SET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal tabpage_set_var";
			} else {
				qDebug() << "tabpage_set_var ->" << data;
				emit on_tabpage_set_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOW:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal tabpage_get_window";
			} else {
				qDebug() << "tabpage_get_window ->" << data;
				emit on_tabpage_get_window(data);
			}

		}
		break;
	case Function::NEOVIM_FN_TABPAGE_IS_VALID:
		{
			bool data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal tabpage_is_valid";
			} else {
				qDebug() << "tabpage_is_valid ->" << data;
				emit on_tabpage_is_valid(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_LINE_COUNT:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_line_count";
			} else {
				qDebug() << "buffer_line_count ->" << data;
				emit on_buffer_line_count(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LINE:
		{
			QByteArray data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_line";
			} else {
				qDebug() << "buffer_get_line ->" << data;
				emit on_buffer_get_line(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_LINE:
		{
			emit on_buffer_set_line();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_DEL_LINE:
		{
			emit on_buffer_del_line();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LINE_SLICE:
		{
			QList<QByteArray> data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_line_slice";
			} else {
				qDebug() << "buffer_get_line_slice ->" << data;
				emit on_buffer_get_line_slice(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_LINE_SLICE:
		{
			emit on_buffer_set_line_slice();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_var";
			} else {
				qDebug() << "buffer_get_var ->" << data;
				emit on_buffer_get_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_VAR:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_set_var";
			} else {
				qDebug() << "buffer_set_var ->" << data;
				emit on_buffer_set_var(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_OPTION:
		{
			QVariant data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_option";
			} else {
				qDebug() << "buffer_get_option ->" << data;
				emit on_buffer_get_option(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_OPTION:
		{
			emit on_buffer_set_option();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NUMBER:
		{
			int64_t data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_number";
			} else {
				qDebug() << "buffer_get_number ->" << data;
				emit on_buffer_get_number(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NAME:
		{
			QByteArray data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_name";
			} else {
				qDebug() << "buffer_get_name ->" << data;
				emit on_buffer_get_name(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_NAME:
		{
			emit on_buffer_set_name();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_IS_VALID:
		{
			bool data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_is_valid";
			} else {
				qDebug() << "buffer_is_valid ->" << data;
				emit on_buffer_is_valid(data);
			}

		}
		break;
	case Function::NEOVIM_FN_BUFFER_INSERT:
		{
			emit on_buffer_insert();

		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_MARK:
		{
			QPoint data;
			if (decodeMsgpack(res, data)) {
				qWarning() << "Error unpacking data for signal buffer_get_mark";
			} else {
				qDebug() << "buffer_get_mark ->" << data;
				emit on_buffer_get_mark(data);
			}

		}
		break;
	default:
		qWarning() << "Received unexpected response";
	}
}

} // Namespace
