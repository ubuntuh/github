#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <Xm/Xm.h>

XmString xs_concat_words(int n, char *words[]) {
    XmString xmstr;
    int i, len = 0;

    if (n <= 0)
        return(XmStringCreate("", XmSTRING_DEFAULT_CHARSET));
    xmstr = (XmString)NULL;
    for (i = 0; i < n; i++) {
        XmString tmp;
        if (i > 0) {
            tmp = XmStringCreate(" ", XmSTRING_DEFAULT_CHARSET);
            xmstr = XmStringConcat(xmstr, tmp);
        }
        tmp = XmStringCreate(words[i], XmSTRING_DEFAULT_CHARSET);
        xmstr = XmStringConcat(xmstr, tmp);
    }
    return xmstr;
}

