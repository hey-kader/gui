#include <gtk/gtk.h>
#include <stdbool.h>
#include <string.h>

#define CHUNK 4096

int fetch_text (char *);
void clicked (void);

void activate (GtkApplication* app, gpointer user_data) {

  GtkWidget *window;
  GtkWidget *button;
	GtkWidget *buffer;
	GtkWidget *view;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "kader");
  gtk_window_set_default_size (GTK_WINDOW (window), 512, 600);

	// button = gtk_button_new_with_label (" ");
	// g_signal_connect (button, "clicked", G_CALLBACK (clicked), NULL);
	char *t = malloc(sizeof(char *)*CHUNK);
	int l = fetch_text(t);
	printf("%s\n%d",t,l);

	//char * text = "this is my test text\n";
	char * text = t;
	buffer = gtk_text_buffer_new(NULL);

	gtk_text_buffer_set_text(buffer,text,strlen(text));
	//gtk_window_set_child(GTK_WINDOW (window), button);

	int ch = gtk_text_buffer_get_char_count(buffer);

	//printf ("char count: %d\n",ch);
	view = gtk_text_view_new_with_buffer(buffer);
	gtk_window_set_child((GTK_WIDGET (window)), view);
	gtk_window_present(GTK_WINDOW (window));

}
void clicked () {
	printf("no touch!\n");
}



int fetch_text (char *text) {
	char c;
	int len = 0;
	FILE * fp = fopen("buffer.txt", "rb");
	while ((c=fgetc(fp)) != EOF) {
		text[len++] = c;
	}
	text[len] = '\0';
	fclose(fp);
	return len;
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
