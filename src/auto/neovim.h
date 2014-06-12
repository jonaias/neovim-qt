// Auto generated Mon Jun 9 22:47:31 2014
#ifndef NEOVIM_QT_NEOVIMOBJ
#define NEOVIM_QT_NEOVIMOBJ
#include "function.h"
#include <msgpack.h>
namespace NeovimQt {
class NeovimConnector;
class Neovim: public QObject
{

	Q_OBJECT
public:
	Neovim(NeovimConnector *);
protected slots:
	void handleResponse(uint32_t id, Function::FunctionId fun, bool error, const msgpack_object&);
signals:
	void error(const QString& errmsg);
private:
	NeovimConnector *m_c;
public slots:
	void tabpage_get_windows(Tabpage tabpage);
	void tabpage_get_var(Tabpage tabpage, String name);
	void tabpage_set_var(Tabpage tabpage, String name, Object value);
	void tabpage_get_window(Tabpage tabpage);
	void tabpage_is_valid(Tabpage tabpage);
	void vim_push_keys(String str);
	void vim_command(String str);
	void vim_command_output(String str);
	void vim_eval(String str);
	void vim_strwidth(String str);
	void vim_list_runtime_paths();
	void vim_change_directory(String dir);
	void vim_get_current_line();
	void vim_set_current_line(String line);
	void vim_del_current_line();
	void vim_get_var(String name);
	void vim_set_var(String name, Object value);
	void vim_get_vvar(String name);
	void vim_get_option(String name);
	void vim_set_option(String name, Object value);
	void vim_out_write(String str);
	void vim_err_write(String str);
	void vim_get_buffers();
	void vim_get_current_buffer();
	void vim_set_current_buffer(Buffer buffer);
	void vim_get_windows();
	void vim_get_current_window();
	void vim_set_current_window(Window window);
	void vim_get_tabpages();
	void vim_get_current_tabpage();
	void vim_set_current_tabpage(Tabpage tabpage);
	void vim_subscribe(String event);
	void vim_unsubscribe(String event);
	void vim_request_screen();
	void buffer_get_length(Buffer buffer);
	void buffer_get_line(Buffer buffer, Integer index);
	void buffer_set_line(Buffer buffer, Integer index, String line);
	void buffer_del_line(Buffer buffer, Integer index);
	void buffer_get_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end);
	void buffer_set_slice(Buffer buffer, Integer start, Integer end, Boolean include_start, Boolean include_end, StringArray replacement);
	void buffer_get_var(Buffer buffer, String name);
	void buffer_set_var(Buffer buffer, String name, Object value);
	void buffer_get_option(Buffer buffer, String name);
	void buffer_set_option(Buffer buffer, String name, Object value);
	void buffer_get_number(Buffer buffer);
	void buffer_get_name(Buffer buffer);
	void buffer_set_name(Buffer buffer, String name);
	void buffer_is_valid(Buffer buffer);
	void buffer_insert(Buffer buffer, Integer lnum, StringArray lines);
	void buffer_get_mark(Buffer buffer, String name);
	void window_get_buffer(Window window);
	void window_get_cursor(Window window);
	void window_set_cursor(Window window, Position pos);
	void window_get_height(Window window);
	void window_set_height(Window window, Integer height);
	void window_get_width(Window window);
	void window_set_width(Window window, Integer width);
	void window_get_var(Window window, String name);
	void window_set_var(Window window, String name, Object value);
	void window_get_option(Window window, String name);
	void window_set_option(Window window, String name, Object value);
	void window_get_position(Window window);
	void window_get_tabpage(Window window);
	void window_is_valid(Window window);

signals:
	void on_tabpage_get_windows(WindowArray);
	void on_tabpage_get_var(Object);
	void on_tabpage_set_var(Object);
	void on_tabpage_get_window(Window);
	void on_tabpage_is_valid(Boolean);
	void on_vim_push_keys(void);
	void on_vim_command(void);
	void on_vim_command_output(String);
	void on_vim_eval(Object);
	void on_vim_strwidth(Integer);
	void on_vim_list_runtime_paths(StringArray);
	void on_vim_change_directory(void);
	void on_vim_get_current_line(String);
	void on_vim_set_current_line(void);
	void on_vim_del_current_line(void);
	void on_vim_get_var(Object);
	void on_vim_set_var(Object);
	void on_vim_get_vvar(Object);
	void on_vim_get_option(Object);
	void on_vim_set_option(void);
	void on_vim_out_write(void);
	void on_vim_err_write(void);
	void on_vim_get_buffers(BufferArray);
	void on_vim_get_current_buffer(Buffer);
	void on_vim_set_current_buffer(void);
	void on_vim_get_windows(WindowArray);
	void on_vim_get_current_window(Window);
	void on_vim_set_current_window(void);
	void on_vim_get_tabpages(TabpageArray);
	void on_vim_get_current_tabpage(Tabpage);
	void on_vim_set_current_tabpage(void);
	void on_vim_subscribe(void);
	void on_vim_unsubscribe(void);
	void on_vim_request_screen(void);
	void on_buffer_get_length(Integer);
	void on_buffer_get_line(String);
	void on_buffer_set_line(void);
	void on_buffer_del_line(void);
	void on_buffer_get_slice(StringArray);
	void on_buffer_set_slice(void);
	void on_buffer_get_var(Object);
	void on_buffer_set_var(Object);
	void on_buffer_get_option(Object);
	void on_buffer_set_option(void);
	void on_buffer_get_number(Integer);
	void on_buffer_get_name(String);
	void on_buffer_set_name(void);
	void on_buffer_is_valid(Boolean);
	void on_buffer_insert(void);
	void on_buffer_get_mark(Position);
	void on_window_get_buffer(Buffer);
	void on_window_get_cursor(Position);
	void on_window_set_cursor(void);
	void on_window_get_height(Integer);
	void on_window_set_height(void);
	void on_window_get_width(Integer);
	void on_window_set_width(void);
	void on_window_get_var(Object);
	void on_window_set_var(Object);
	void on_window_get_option(Object);
	void on_window_set_option(void);
	void on_window_get_position(Position);
	void on_window_get_tabpage(Tabpage);
	void on_window_is_valid(Boolean);
};
} // namespace
#endif
