#include <gtkmm.h>
#include <webkitgtk-6.0/webkit/webkit.h>  // WebKitGTK 6 headers

class BrowserWindow : public Gtk::Window
{
public:
    BrowserWindow();

private:
    void on_entry_activate();

    Gtk::Box vbox{Gtk::Orientation::VERTICAL};
    Gtk::HeaderBar headerBar;
    Gtk::Entry urlEntry;
    Gtk::ScrolledWindow scrolled;

    WebKitWebView* webview;
};

BrowserWindow::BrowserWindow()
{
    set_default_size(1024, 768);
    set_title("GTK 4 + WebKitGTK 6 Browser");

    headerBar.set_title_widget(urlEntry);
    set_titlebar(headerBar);

    urlEntry.set_placeholder_text("Enter URL...");
    urlEntry.signal_activate().connect(sigc::mem_fun(*this, &BrowserWindow::on_entry_activate));

    // Create WebKit webview
    webview = WEBKIT_WEB_VIEW(webkit_web_view_new());

    // Wrap in scrolled window
    scrolled.set_child(*Gtk::manage(Glib::wrap(GTK_WIDGET(webview))));

    vbox.append(scrolled);
    set_child(vbox);

    // Load initial page
    webkit_web_view_load_uri(webview, "https://www.example.com");
}

void BrowserWindow::on_entry_activate()
{
    std::string url = urlEntry.get_text();
    if (!url.empty())
    {
        if (!url.starts_with("http://") && !url.starts_with("https://"))
            url = "http://" + url;
        webkit_web_view_load_uri(webview, url.c_str());
    }
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.browser");
    BrowserWindow window;
    return app->run();
}
