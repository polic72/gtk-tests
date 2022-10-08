/**
 * @file
 * @brief This is the code for testing the Hello World of the GTK framework.
 * 	  Uses the code found at: https://www.gtk.org/docs/getting-started/hello-world/.
 */
 

#include <gtk/gtk.h>


/**
 * Simply prints "Hello World" to standard output.
 *
 * Contains two different new ways to print. Not sure how the "gprint" option differs from the "printf" option just yet.
 * @param[in] widget Not sure what this does.
 * @param[in] data Not sure what this does.
 */
static void print_hello(GtkWidget* widget, gpointer data)
{
	//This is apparently some GTK printing method.
	//g_print("Hello World\n");
	
	//But this seems to work too.
	printf("Hello World\n");
}


/**
 * The activation code.
 *
 * This code takes a GtkApplication to create a window and populate it with a button that prints "Hello World" when clicked.
 * @param[in] app GtkApplication* that points to the app to attach to.
 * @param[in] user_data No idea what this does, but here we are.
 */
static void activate(GtkApplication* app, gpointer user_data)
{
	GtkWidget* window;
	GtkWidget* button;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	gtk_window_set_child(GTK_WINDOW(window), button);

	gtk_window_present(GTK_WINDOW(window));
}


/**
 * The main method.
 *
 * Initializes the GTK application, runs it, and exits after it is completed.
 * @param[in] argc The number of command-line arguments passed.
 * @param[in] argv The command-line arguments passed.
 * @return The status of the GTK application on its closing.
 */
int main(int argc, char** argv)
{
	GtkApplication* app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);

	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

	status = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref(app);

	return status;
}
