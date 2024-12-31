void 
hidewin(const Arg *arg) {
    if (!selmon->sel)
        return;
    Client *c = (Client *)selmon->sel;
    hide(c);
    hiddenWinStack[++hiddenWinStackTop] = c;
}

void
restorewin(const Arg *arg) {
    int i = hiddenWinStackTop;
    while (i > -1) {
        if (HIDDEN(hiddenWinStack[i]) &&
            hiddenWinStack[i]->tags == selmon->tagset[selmon->seltags]) {
            show(hiddenWinStack[i]);
            focus(hiddenWinStack[i]);
            restack(selmon);
            for (int j = i; j < hiddenWinStackTop; ++j) {
                hiddenWinStack[j] = hiddenWinStack[j + 1];
            }
            --hiddenWinStackTop;
            return;
        }
        --i;
    }
}

void
hideotherwins(const Arg *arg) {
    Client *c = NULL, *i;
    if (!selmon->sel)
        return;
    c = (Client *)selmon->sel;
    for (i = selmon->clients; i; i = i->next) {
        if (i != c && ISVISIBLE(i)) {
            hide(i);
            hiddenWinStack[++hiddenWinStackTop] = i;
        }
    }
}

void
restoreotherwins(const Arg *arg) {
    int i;
    for (i = 0; i <= hiddenWinStackTop; ++i) {
        if (HIDDEN(hiddenWinStack[i]) &&
            hiddenWinStack[i]->tags == selmon->tagset[selmon->seltags]) {
            show(hiddenWinStack[i]);
            restack(selmon);
            memcpy(hiddenWinStack + i, hiddenWinStack + i + 1,
                   (hiddenWinStackTop - i) * sizeof(Client *));
            --hiddenWinStackTop;
            --i;
        }
    }
}

int
issinglewin(const Arg *arg) {
    Client *c = NULL;
    int cot = 0;
    int tag = selmon->tagset[selmon->seltags];
    for (c = selmon->clients; c; c = c->next) {
        if (ISVISIBLE(c) && !HIDDEN(c) && c->tags == tag) {
            cot++;
        }
        if (cot > 1) {
            return 0;
        }
    }
    return 1;
}

void
focuswin(const Arg *arg) {
    Client *c = NULL, *i;
    int j;

    if (arg->i > 0) {
        for (c = selmon->sel->next;
             c && !(c->tags == selmon->tagset[selmon->seltags]); c = c->next)
            ;
        if (!c)
            for (c = selmon->clients;
                 c && !(c->tags == selmon->tagset[selmon->seltags]);
                 c = c->next)
                ;
    } else {
        for (i = selmon->clients; i != selmon->sel; i = i->next)
            if (i->tags == selmon->tagset[selmon->seltags])
                c = i;
        if (!c)
            for (; i; i = i->next)
                if (i->tags == selmon->tagset[selmon->seltags])
                    c = i;
    }

    i = selmon->sel;

    if (c && c != i) {
        hide(i);
        for (j = 0; j <= hiddenWinStackTop; ++j) {
            if (HIDDEN(hiddenWinStack[j]) &&
                hiddenWinStack[j]->tags == selmon->tagset[selmon->seltags] &&
                hiddenWinStack[j] == c) {
                show(c);
                focus(c);
                restack(selmon);
                memcpy(hiddenWinStack + j, hiddenWinStack + j + 1,
                       (hiddenWinStackTop - j) * sizeof(Client *));
                hiddenWinStack[hiddenWinStackTop] = i;
                return;
            }
        }
    }
}
