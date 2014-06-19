// Auto generated Thu Jun 19 11:10:11 2014
#include "neovim.h"
#include "neovimconnector.h"
namespace NeovimQt {
Neovim::Neovim(NeovimConnector *c)
:m_c(c)
{
}

void Neovim::tabpage_get_windows(Tabpage tabpage)
{
	r_tabpage_get_windows(tabpage);
}

NeovimRequest* Neovim::r_tabpage_get_windows(Tabpage tabpage)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_TABPAGE_GET_WINDOWS, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	return r;
}

void Neovim::tabpage_get_var(Tabpage tabpage, String name)
{
	r_tabpage_get_var(tabpage, name);
}

NeovimRequest* Neovim::r_tabpage_get_var(Tabpage tabpage, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_TABPAGE_GET_VAR, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	m_c->send(name);
	return r;
}

void Neovim::tabpage_set_var(Tabpage tabpage, String name, Object value)
{
	r_tabpage_set_var(tabpage, name, value);
}

NeovimRequest* Neovim::r_tabpage_set_var(Tabpage tabpage, String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_TABPAGE_SET_VAR, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::tabpage_get_window(Tabpage tabpage)
{
	r_tabpage_get_window(tabpage);
}

NeovimRequest* Neovim::r_tabpage_get_window(Tabpage tabpage)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_TABPAGE_GET_WINDOW, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	return r;
}

void Neovim::tabpage_is_valid(Tabpage tabpage)
{
	r_tabpage_is_valid(tabpage);
}

NeovimRequest* Neovim::r_tabpage_is_valid(Tabpage tabpage)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_TABPAGE_IS_VALID, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	return r;
}

void Neovim::vim_push_keys(String str)
{
	r_vim_push_keys(str);
}

NeovimRequest* Neovim::r_vim_push_keys(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_PUSH_KEYS, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_command(String str)
{
	r_vim_command(str);
}

NeovimRequest* Neovim::r_vim_command(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_COMMAND, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_command_output(String str)
{
	r_vim_command_output(str);
}

NeovimRequest* Neovim::r_vim_command_output(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_COMMAND_OUTPUT, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_eval(String str)
{
	r_vim_eval(str);
}

NeovimRequest* Neovim::r_vim_eval(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_EVAL, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_strwidth(String str)
{
	r_vim_strwidth(str);
}

NeovimRequest* Neovim::r_vim_strwidth(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_STRWIDTH, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_list_runtime_paths()
{
	r_vim_list_runtime_paths();
}

NeovimRequest* Neovim::r_vim_list_runtime_paths()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_LIST_RUNTIME_PATHS, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_change_directory(String dir)
{
	r_vim_change_directory(dir);
}

NeovimRequest* Neovim::r_vim_change_directory(String dir)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_CHANGE_DIRECTORY, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(dir);
	return r;
}

void Neovim::vim_get_current_line()
{
	r_vim_get_current_line();
}

NeovimRequest* Neovim::r_vim_get_current_line()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_CURRENT_LINE, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_set_current_line(String line)
{
	r_vim_set_current_line(line);
}

NeovimRequest* Neovim::r_vim_set_current_line(String line)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_CURRENT_LINE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(line);
	return r;
}

void Neovim::vim_del_current_line()
{
	r_vim_del_current_line();
}

NeovimRequest* Neovim::r_vim_del_current_line()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_DEL_CURRENT_LINE, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_get_var(String name)
{
	r_vim_get_var(name);
}

NeovimRequest* Neovim::r_vim_get_var(String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_VAR, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(name);
	return r;
}

void Neovim::vim_set_var(String name, Object value)
{
	r_vim_set_var(name, value);
}

NeovimRequest* Neovim::r_vim_set_var(String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_VAR, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::vim_get_vvar(String name)
{
	r_vim_get_vvar(name);
}

NeovimRequest* Neovim::r_vim_get_vvar(String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_VVAR, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(name);
	return r;
}

void Neovim::vim_get_option(String name)
{
	r_vim_get_option(name);
}

NeovimRequest* Neovim::r_vim_get_option(String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_OPTION, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(name);
	return r;
}

void Neovim::vim_set_option(String name, Object value)
{
	r_vim_set_option(name, value);
}

NeovimRequest* Neovim::r_vim_set_option(String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_OPTION, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::vim_out_write(String str)
{
	r_vim_out_write(str);
}

NeovimRequest* Neovim::r_vim_out_write(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_OUT_WRITE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_err_write(String str)
{
	r_vim_err_write(str);
}

NeovimRequest* Neovim::r_vim_err_write(String str)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_ERR_WRITE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(str);
	return r;
}

void Neovim::vim_get_buffers()
{
	r_vim_get_buffers();
}

NeovimRequest* Neovim::r_vim_get_buffers()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_BUFFERS, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_get_current_buffer()
{
	r_vim_get_current_buffer();
}

NeovimRequest* Neovim::r_vim_get_current_buffer()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_CURRENT_BUFFER, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_set_current_buffer(Buffer buffer)
{
	r_vim_set_current_buffer(buffer);
}

NeovimRequest* Neovim::r_vim_set_current_buffer(Buffer buffer)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_CURRENT_BUFFER, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	return r;
}

void Neovim::vim_get_windows()
{
	r_vim_get_windows();
}

NeovimRequest* Neovim::r_vim_get_windows()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_WINDOWS, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_get_current_window()
{
	r_vim_get_current_window();
}

NeovimRequest* Neovim::r_vim_get_current_window()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_CURRENT_WINDOW, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_set_current_window(Window window)
{
	r_vim_set_current_window(window);
}

NeovimRequest* Neovim::r_vim_set_current_window(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_CURRENT_WINDOW, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::vim_get_tabpages()
{
	r_vim_get_tabpages();
}

NeovimRequest* Neovim::r_vim_get_tabpages()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_TABPAGES, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_get_current_tabpage()
{
	r_vim_get_current_tabpage();
}

NeovimRequest* Neovim::r_vim_get_current_tabpage()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_GET_CURRENT_TABPAGE, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::vim_set_current_tabpage(Tabpage tabpage)
{
	r_vim_set_current_tabpage(tabpage);
}

NeovimRequest* Neovim::r_vim_set_current_tabpage(Tabpage tabpage)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SET_CURRENT_TABPAGE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(tabpage);
	return r;
}

void Neovim::vim_subscribe(String event)
{
	r_vim_subscribe(event);
}

NeovimRequest* Neovim::r_vim_subscribe(String event)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_SUBSCRIBE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(event);
	return r;
}

void Neovim::vim_unsubscribe(String event)
{
	r_vim_unsubscribe(event);
}

NeovimRequest* Neovim::r_vim_unsubscribe(String event)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_UNSUBSCRIBE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(event);
	return r;
}

void Neovim::vim_request_screen()
{
	r_vim_request_screen();
}

NeovimRequest* Neovim::r_vim_request_screen()
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_VIM_REQUEST_SCREEN, 0);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	return r;
}

void Neovim::buffer_get_length(Buffer buffer)
{
	r_buffer_get_length(buffer);
}

NeovimRequest* Neovim::r_buffer_get_length(Buffer buffer)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_LENGTH, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	return r;
}

void Neovim::buffer_get_line(Buffer buffer, Integer index)
{
	r_buffer_get_line(buffer, index);
}

NeovimRequest* Neovim::r_buffer_get_line(Buffer buffer, Integer index)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_LINE, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(index);
	return r;
}

void Neovim::buffer_set_line(Buffer buffer, Integer index, String line)
{
	r_buffer_set_line(buffer, index, line);
}

NeovimRequest* Neovim::r_buffer_set_line(Buffer buffer, Integer index, String line)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_SET_LINE, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(index);
	m_c->send(line);
	return r;
}

void Neovim::buffer_del_line(Buffer buffer, Integer index)
{
	r_buffer_del_line(buffer, index);
}

NeovimRequest* Neovim::r_buffer_del_line(Buffer buffer, Integer index)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_DEL_LINE, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(index);
	return r;
}

void Neovim::buffer_get_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end)
{
	r_buffer_get_slice(buffer, start, end, include_start, include_end);
}

NeovimRequest* Neovim::r_buffer_get_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_SLICE, 5);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(start);
	m_c->send(end);
	m_c->send(include_start);
	m_c->send(include_end);
	return r;
}

void Neovim::buffer_set_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end, StringArray replacement)
{
	r_buffer_set_slice(buffer, start, end, include_start, include_end, replacement);
}

NeovimRequest* Neovim::r_buffer_set_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end, StringArray replacement)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_SET_SLICE, 6);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(start);
	m_c->send(end);
	m_c->send(include_start);
	m_c->send(include_end);
	m_c->send(replacement);
	return r;
}

void Neovim::buffer_get_var(Buffer buffer, String name)
{
	r_buffer_get_var(buffer, name);
}

NeovimRequest* Neovim::r_buffer_get_var(Buffer buffer, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_VAR, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	return r;
}

void Neovim::buffer_set_var(Buffer buffer, String name, Object value)
{
	r_buffer_set_var(buffer, name, value);
}

NeovimRequest* Neovim::r_buffer_set_var(Buffer buffer, String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_SET_VAR, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::buffer_get_option(Buffer buffer, String name)
{
	r_buffer_get_option(buffer, name);
}

NeovimRequest* Neovim::r_buffer_get_option(Buffer buffer, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_OPTION, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	return r;
}

void Neovim::buffer_set_option(Buffer buffer, String name, Object value)
{
	r_buffer_set_option(buffer, name, value);
}

NeovimRequest* Neovim::r_buffer_set_option(Buffer buffer, String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_SET_OPTION, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::buffer_get_number(Buffer buffer)
{
	r_buffer_get_number(buffer);
}

NeovimRequest* Neovim::r_buffer_get_number(Buffer buffer)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_NUMBER, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	return r;
}

void Neovim::buffer_get_name(Buffer buffer)
{
	r_buffer_get_name(buffer);
}

NeovimRequest* Neovim::r_buffer_get_name(Buffer buffer)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_NAME, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	return r;
}

void Neovim::buffer_set_name(Buffer buffer, String name)
{
	r_buffer_set_name(buffer, name);
}

NeovimRequest* Neovim::r_buffer_set_name(Buffer buffer, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_SET_NAME, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	return r;
}

void Neovim::buffer_is_valid(Buffer buffer)
{
	r_buffer_is_valid(buffer);
}

NeovimRequest* Neovim::r_buffer_is_valid(Buffer buffer)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_IS_VALID, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	return r;
}

void Neovim::buffer_insert(Buffer buffer, Integer lnum, StringArray lines)
{
	r_buffer_insert(buffer, lnum, lines);
}

NeovimRequest* Neovim::r_buffer_insert(Buffer buffer, Integer lnum, StringArray lines)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_INSERT, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(lnum);
	m_c->send(lines);
	return r;
}

void Neovim::buffer_get_mark(Buffer buffer, String name)
{
	r_buffer_get_mark(buffer, name);
}

NeovimRequest* Neovim::r_buffer_get_mark(Buffer buffer, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_BUFFER_GET_MARK, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(buffer);
	m_c->send(name);
	return r;
}

void Neovim::window_get_buffer(Window window)
{
	r_window_get_buffer(window);
}

NeovimRequest* Neovim::r_window_get_buffer(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_BUFFER, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_get_cursor(Window window)
{
	r_window_get_cursor(window);
}

NeovimRequest* Neovim::r_window_get_cursor(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_CURSOR, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_set_cursor(Window window, Position pos)
{
	r_window_set_cursor(window, pos);
}

NeovimRequest* Neovim::r_window_set_cursor(Window window, Position pos)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_SET_CURSOR, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(pos);
	return r;
}

void Neovim::window_get_height(Window window)
{
	r_window_get_height(window);
}

NeovimRequest* Neovim::r_window_get_height(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_HEIGHT, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_set_height(Window window, Integer height)
{
	r_window_set_height(window, height);
}

NeovimRequest* Neovim::r_window_set_height(Window window, Integer height)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_SET_HEIGHT, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(height);
	return r;
}

void Neovim::window_get_width(Window window)
{
	r_window_get_width(window);
}

NeovimRequest* Neovim::r_window_get_width(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_WIDTH, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_set_width(Window window, Integer width)
{
	r_window_set_width(window, width);
}

NeovimRequest* Neovim::r_window_set_width(Window window, Integer width)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_SET_WIDTH, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(width);
	return r;
}

void Neovim::window_get_var(Window window, String name)
{
	r_window_get_var(window, name);
}

NeovimRequest* Neovim::r_window_get_var(Window window, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_VAR, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(name);
	return r;
}

void Neovim::window_set_var(Window window, String name, Object value)
{
	r_window_set_var(window, name, value);
}

NeovimRequest* Neovim::r_window_set_var(Window window, String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_SET_VAR, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::window_get_option(Window window, String name)
{
	r_window_get_option(window, name);
}

NeovimRequest* Neovim::r_window_get_option(Window window, String name)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_OPTION, 2);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(name);
	return r;
}

void Neovim::window_set_option(Window window, String name, Object value)
{
	r_window_set_option(window, name, value);
}

NeovimRequest* Neovim::r_window_set_option(Window window, String name, Object value)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_SET_OPTION, 3);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	m_c->send(name);
	m_c->send(value);
	return r;
}

void Neovim::window_get_position(Window window)
{
	r_window_get_position(window);
}

NeovimRequest* Neovim::r_window_get_position(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_POSITION, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_get_tabpage(Window window)
{
	r_window_get_tabpage(window);
}

NeovimRequest* Neovim::r_window_get_tabpage(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_GET_TABPAGE, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::window_is_valid(Window window)
{
	r_window_is_valid(window);
}

NeovimRequest* Neovim::r_window_is_valid(Window window)
{
	NeovimRequest *r = m_c->startRequest(Function::NEOVIM_FN_WINDOW_IS_VALID, 1);
	connect(r, &NeovimRequest::finished, this, &Neovim::handleResponse);
	m_c->send(window);
	return r;
}

void Neovim::handleResponse(uint32_t msgid, Function::FunctionId fun, bool failed, const msgpack_object& res)
{
	bool convfail=true;
	if (failed) {
		emit error(m_c->to_String(res));
		return;
	}

	switch(fun) {
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOWS:
		{
			WindowArray data = m_c->to_WindowArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal tabpage_get_windows";
			} else {
				qDebug() << "tabpage_get_windows ->" << data;
				emit on_tabpage_get_windows(data);
			}
		}
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal tabpage_get_var";
			} else {
				qDebug() << "tabpage_get_var ->" << data;
				emit on_tabpage_get_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_TABPAGE_SET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal tabpage_set_var";
			} else {
				qDebug() << "tabpage_set_var ->" << data;
				emit on_tabpage_set_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_TABPAGE_GET_WINDOW:
		{
			Window data = m_c->to_Window(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal tabpage_get_window";
			} else {
				qDebug() << "tabpage_get_window ->" << data;
				emit on_tabpage_get_window(data);
			}
		}
		break;
	case Function::NEOVIM_FN_TABPAGE_IS_VALID:
		{
			Boolean data = m_c->to_Boolean(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal tabpage_is_valid";
			} else {
				qDebug() << "tabpage_is_valid ->" << data;
				emit on_tabpage_is_valid(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_PUSH_KEYS:
		{
			qDebug() << "on_vim_push_keys";
			emit on_vim_push_keys();
		}
		break;
	case Function::NEOVIM_FN_VIM_COMMAND:
		{
			qDebug() << "on_vim_command";
			emit on_vim_command();
		}
		break;
	case Function::NEOVIM_FN_VIM_COMMAND_OUTPUT:
		{
			String data = m_c->to_String(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_command_output";
			} else {
				qDebug() << "vim_command_output ->" << data;
				emit on_vim_command_output(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_EVAL:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_eval";
			} else {
				qDebug() << "vim_eval ->" << data;
				emit on_vim_eval(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_STRWIDTH:
		{
			Integer data = m_c->to_Integer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_strwidth";
			} else {
				qDebug() << "vim_strwidth ->" << data;
				emit on_vim_strwidth(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_LIST_RUNTIME_PATHS:
		{
			StringArray data = m_c->to_StringArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_list_runtime_paths";
			} else {
				qDebug() << "vim_list_runtime_paths ->" << data;
				emit on_vim_list_runtime_paths(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_CHANGE_DIRECTORY:
		{
			qDebug() << "on_vim_change_directory";
			emit on_vim_change_directory();
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_LINE:
		{
			String data = m_c->to_String(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_current_line";
			} else {
				qDebug() << "vim_get_current_line ->" << data;
				emit on_vim_get_current_line(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_LINE:
		{
			qDebug() << "on_vim_set_current_line";
			emit on_vim_set_current_line();
		}
		break;
	case Function::NEOVIM_FN_VIM_DEL_CURRENT_LINE:
		{
			qDebug() << "on_vim_del_current_line";
			emit on_vim_del_current_line();
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_var";
			} else {
				qDebug() << "vim_get_var ->" << data;
				emit on_vim_get_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_set_var";
			} else {
				qDebug() << "vim_set_var ->" << data;
				emit on_vim_set_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_VVAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_vvar";
			} else {
				qDebug() << "vim_get_vvar ->" << data;
				emit on_vim_get_vvar(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_OPTION:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_option";
			} else {
				qDebug() << "vim_get_option ->" << data;
				emit on_vim_get_option(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_OPTION:
		{
			qDebug() << "on_vim_set_option";
			emit on_vim_set_option();
		}
		break;
	case Function::NEOVIM_FN_VIM_OUT_WRITE:
		{
			qDebug() << "on_vim_out_write";
			emit on_vim_out_write();
		}
		break;
	case Function::NEOVIM_FN_VIM_ERR_WRITE:
		{
			qDebug() << "on_vim_err_write";
			emit on_vim_err_write();
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_BUFFERS:
		{
			BufferArray data = m_c->to_BufferArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_buffers";
			} else {
				qDebug() << "vim_get_buffers ->" << data;
				emit on_vim_get_buffers(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_BUFFER:
		{
			Buffer data = m_c->to_Buffer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_current_buffer";
			} else {
				qDebug() << "vim_get_current_buffer ->" << data;
				emit on_vim_get_current_buffer(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_BUFFER:
		{
			qDebug() << "on_vim_set_current_buffer";
			emit on_vim_set_current_buffer();
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_WINDOWS:
		{
			WindowArray data = m_c->to_WindowArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_windows";
			} else {
				qDebug() << "vim_get_windows ->" << data;
				emit on_vim_get_windows(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_WINDOW:
		{
			Window data = m_c->to_Window(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_current_window";
			} else {
				qDebug() << "vim_get_current_window ->" << data;
				emit on_vim_get_current_window(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_WINDOW:
		{
			qDebug() << "on_vim_set_current_window";
			emit on_vim_set_current_window();
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_TABPAGES:
		{
			TabpageArray data = m_c->to_TabpageArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_tabpages";
			} else {
				qDebug() << "vim_get_tabpages ->" << data;
				emit on_vim_get_tabpages(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_GET_CURRENT_TABPAGE:
		{
			Tabpage data = m_c->to_Tabpage(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal vim_get_current_tabpage";
			} else {
				qDebug() << "vim_get_current_tabpage ->" << data;
				emit on_vim_get_current_tabpage(data);
			}
		}
		break;
	case Function::NEOVIM_FN_VIM_SET_CURRENT_TABPAGE:
		{
			qDebug() << "on_vim_set_current_tabpage";
			emit on_vim_set_current_tabpage();
		}
		break;
	case Function::NEOVIM_FN_VIM_SUBSCRIBE:
		{
			qDebug() << "on_vim_subscribe";
			emit on_vim_subscribe();
		}
		break;
	case Function::NEOVIM_FN_VIM_UNSUBSCRIBE:
		{
			qDebug() << "on_vim_unsubscribe";
			emit on_vim_unsubscribe();
		}
		break;
	case Function::NEOVIM_FN_VIM_REQUEST_SCREEN:
		{
			qDebug() << "on_vim_request_screen";
			emit on_vim_request_screen();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LENGTH:
		{
			Integer data = m_c->to_Integer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_length";
			} else {
				qDebug() << "buffer_get_length ->" << data;
				emit on_buffer_get_length(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_LINE:
		{
			String data = m_c->to_String(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_line";
			} else {
				qDebug() << "buffer_get_line ->" << data;
				emit on_buffer_get_line(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_LINE:
		{
			qDebug() << "on_buffer_set_line";
			emit on_buffer_set_line();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_DEL_LINE:
		{
			qDebug() << "on_buffer_del_line";
			emit on_buffer_del_line();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_SLICE:
		{
			StringArray data = m_c->to_StringArray(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_slice";
			} else {
				qDebug() << "buffer_get_slice ->" << data;
				emit on_buffer_get_slice(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_SLICE:
		{
			qDebug() << "on_buffer_set_slice";
			emit on_buffer_set_slice();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_var";
			} else {
				qDebug() << "buffer_get_var ->" << data;
				emit on_buffer_get_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_set_var";
			} else {
				qDebug() << "buffer_set_var ->" << data;
				emit on_buffer_set_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_OPTION:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_option";
			} else {
				qDebug() << "buffer_get_option ->" << data;
				emit on_buffer_get_option(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_OPTION:
		{
			qDebug() << "on_buffer_set_option";
			emit on_buffer_set_option();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NUMBER:
		{
			Integer data = m_c->to_Integer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_number";
			} else {
				qDebug() << "buffer_get_number ->" << data;
				emit on_buffer_get_number(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_NAME:
		{
			String data = m_c->to_String(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_name";
			} else {
				qDebug() << "buffer_get_name ->" << data;
				emit on_buffer_get_name(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_SET_NAME:
		{
			qDebug() << "on_buffer_set_name";
			emit on_buffer_set_name();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_IS_VALID:
		{
			Boolean data = m_c->to_Boolean(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_is_valid";
			} else {
				qDebug() << "buffer_is_valid ->" << data;
				emit on_buffer_is_valid(data);
			}
		}
		break;
	case Function::NEOVIM_FN_BUFFER_INSERT:
		{
			qDebug() << "on_buffer_insert";
			emit on_buffer_insert();
		}
		break;
	case Function::NEOVIM_FN_BUFFER_GET_MARK:
		{
			Position data = m_c->to_Position(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal buffer_get_mark";
			} else {
				qDebug() << "buffer_get_mark ->" << data;
				emit on_buffer_get_mark(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_BUFFER:
		{
			Buffer data = m_c->to_Buffer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_buffer";
			} else {
				qDebug() << "window_get_buffer ->" << data;
				emit on_window_get_buffer(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_CURSOR:
		{
			Position data = m_c->to_Position(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_cursor";
			} else {
				qDebug() << "window_get_cursor ->" << data;
				emit on_window_get_cursor(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_CURSOR:
		{
			qDebug() << "on_window_set_cursor";
			emit on_window_set_cursor();
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_HEIGHT:
		{
			Integer data = m_c->to_Integer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_height";
			} else {
				qDebug() << "window_get_height ->" << data;
				emit on_window_get_height(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_HEIGHT:
		{
			qDebug() << "on_window_set_height";
			emit on_window_set_height();
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_WIDTH:
		{
			Integer data = m_c->to_Integer(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_width";
			} else {
				qDebug() << "window_get_width ->" << data;
				emit on_window_get_width(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_WIDTH:
		{
			qDebug() << "on_window_set_width";
			emit on_window_set_width();
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_var";
			} else {
				qDebug() << "window_get_var ->" << data;
				emit on_window_get_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_VAR:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_set_var";
			} else {
				qDebug() << "window_set_var ->" << data;
				emit on_window_set_var(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_OPTION:
		{
			Object data = m_c->to_Object(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_option";
			} else {
				qDebug() << "window_get_option ->" << data;
				emit on_window_get_option(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_SET_OPTION:
		{
			qDebug() << "on_window_set_option";
			emit on_window_set_option();
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_POSITION:
		{
			Position data = m_c->to_Position(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_position";
			} else {
				qDebug() << "window_get_position ->" << data;
				emit on_window_get_position(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_GET_TABPAGE:
		{
			Tabpage data = m_c->to_Tabpage(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_get_tabpage";
			} else {
				qDebug() << "window_get_tabpage ->" << data;
				emit on_window_get_tabpage(data);
			}
		}
		break;
	case Function::NEOVIM_FN_WINDOW_IS_VALID:
		{
			Boolean data = m_c->to_Boolean(res, &convfail);
			if (convfail) {
				qWarning() << "Error unpacking data for signal window_is_valid";
			} else {
				qDebug() << "window_is_valid ->" << data;
				emit on_window_is_valid(data);
			}
		}
		break;
	default:
		qWarning() << "Received unexpected response";
	}
}
} // namespace
