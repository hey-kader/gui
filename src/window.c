#include <gtk/gtk.h>
#include <stdbool.h>
#include <string.h>

void clicked (void);

void activate (GtkApplication* app, gpointer user_data) {

  GtkWidget *window;
  GtkWidget *button;
	GtkWidget *view;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "kader");
  gtk_window_set_default_size (GTK_WINDOW (window), 512, 600);

	// button = gtk_button_new_with_label (" ");
	// g_signal_connect (button, "clicked", G_CALLBACK (clicked), NULL);

	char * text = "this is my test text\n";
	view = gtk_text_buffer_new(NULL);

	gtk_text_buffer_set_text(view,text,strlen(text));
	// gtk_window_set_child(GTK_WINDOW (window), button);

	int ch = gtk_text_buffer_get_char_count(view);

	printf ("char count: %d\n",ch);
	gtk_window_present(GTK_WINDOW (window));

}
void clicked () {
	printf("no touch!\n");
}

int main (int argc, char *argv[]) {

  GtkApplication *app;
  int status;

  app = gtk_application_new ("kader.gtk", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;

}
