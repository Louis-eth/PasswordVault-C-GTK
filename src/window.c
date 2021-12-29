#include <gtk-3.0/gtk/gtk.h>

#include "header.h"

void close_window(GtkWidget *widget, gpointer window)
{
    gtk_window_close(window);
}

GtkWidget *usernameEntry, *passwordEntry;

void test(GtkButton *button,gpointer data){
  g_print("it's work");
}
void verification(GtkWidget *button,gpointer app){
    const gchar *user = gtk_entry_get_text(GTK_ENTRY(usernameEntry));
    const gchar *pwd = gtk_entry_get_text(GTK_ENTRY(passwordEntry));
    
    if(strcmp(user,"root")==0 && strcmp(pwd,"toor")==0){
      show_data();
      g_application_quit(G_APPLICATION(app));
    }

}

void activate(GtkApplication *app,gpointer user_data){

  GtkWidget *window, *fixed;

  GtkWidget *header;
  GtkWidget *btn1;

  GtkCssProvider *provider;
  GdkDisplay *display;
  GdkScreen *screen;

  GtkStyleContext *context;

  const int WINDOW_WIDTH = 500;
  const int WINDOW_HEIGHT = 100;
  window = gtk_application_window_new(GTK_APPLICATION(app));
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window),"Log in");
  gtk_window_set_default_size(GTK_WINDOW(window),WINDOW_WIDTH,WINDOW_HEIGHT);
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(window),FALSE);


  provider = gtk_css_provider_new();
  display = gdk_display_get_default();
  screen = gdk_display_get_default_screen(display);
  gtk_style_context_add_provider_for_screen(screen,GTK_STYLE_PROVIDER(provider),GTK_STYLE_PROVIDER_PRIORITY_USER);
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(provider),"style.css",NULL);

  header = gtk_label_new("Welcome,");
  context = gtk_widget_get_style_context(header);
  gtk_style_context_add_class(context,"header");

  usernameEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(usernameEntry),"Username");
  
  passwordEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(passwordEntry),"Password");
  gtk_entry_set_visibility(GTK_ENTRY(passwordEntry),FALSE);

  btn1 = gtk_button_new_with_label("Log In");
  g_signal_connect(btn1,"clicked",G_CALLBACK(verification),app);

  GtkWidget *box;
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
  gtk_container_set_border_width(GTK_CONTAINER(box),50);
  gtk_box_pack_start(GTK_BOX(box), header, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), usernameEntry, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), passwordEntry, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), btn1, FALSE, FALSE, 0);

  gtk_container_add(GTK_CONTAINER(window), box); 

  gtk_widget_show_all(window);
}

