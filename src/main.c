/*

Author : Louss-exe

compil : gcc $(pkg-config --cflags gtk+-3.0) main.c -o main $(pkg-config --libs gtk+-3.0)

:-)

*/

#include <gtk-3.0/gtk/gtk.h>

#include "header.h"

int main(int argc,char **argv){

  GtkApplication *app;
  int status;

  app = gtk_application_new ("eth.gtk-login", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref (app);

  return status;
}