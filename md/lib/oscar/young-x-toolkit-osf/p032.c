/* gcc -o a.out p032.c p035.c -lXm -lXt -lX11 */
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <Xm/Xm.h>
#include <Xm/Label.h>

extern XmString xs_concat_words(int n, char *words[]);

int main(int argc, char *argv[]) {
    Widget toplevel, msg_widget;
    Arg wargs[1];
    int n;
    char *message;

    toplevel = XtInitialize(argv[0], "Memo", NULL, 0, &argc, argv);
    n = 0;
    if ((message = xs_concat_words(argc - 1, &argv[1])) != NULL) {
        XtSetArg(wargs[n], XmNlabelString, message);
        n++;
    }
    msg_widget = XtCreateManagedWidget("msg", xmLabelWidgetClass, toplevel, wargs, n);
    XtRealizeWidget(toplevel);
    XtMainLoop();
}

