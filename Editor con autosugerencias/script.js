// document.addEventListener('DOMContentLoaded', () => {
//     const trie = new Trie();

    // const words = [
    //     "abstract", "and", "array", "as", "break", "callable", "case", "catch", "class", "clone",
    //     "const", "continue", "declare", "default", "do", "else", "elseif", "enddeclare", "endfor",
    //     "endforeach", "endif", "endswitch", "endwhile", "extends", "final", "finally", "for",
    //     "foreach", "function", "global", "goto", "if", "implements", "include", "include_once",
    //     "instanceof", "insteadof", "interface", "isset", "list", "namespace", "new", "or", "print",
    //     "private", "protected", "public", "require", "require_once", "return", "static", "switch",
    //     "throw", "trait", "try", "unset", "use", "var", "while", "xor", "yield"
    // ];


document.addEventListener('DOMContentLoaded', () => {
    const trie = new Trie();
    const keywords = [
        "abstract", "and", "array", "as", "break", "callable", "case", "catch", "class", "clone",
        "const", "continue", "declare", "default", "do", "else", "elseif", "enddeclare", "endfor",
        "endforeach", "endif", "endswitch", "endwhile", "extends", "final", "finally", "for",
        "foreach", "function", "global", "goto", "if", "implements", "include", "include_once",
        "instanceof", "insteadof", "interface", "isset", "list", "namespace", "new", "or", "print",
        "private", "protected", "public", "require", "require_once", "return", "static", "switch",
        "throw", "trait", "try", "unset", "use", "var", "while", "xor", "yield"
    ];
    keywords.forEach(word => trie.insert(word));

    const editor = CodeMirror.fromTextArea(document.getElementById('code-editor'), {
        mode: 'javascript',
        lineNumbers: true,
        extraKeys: { "Ctrl-Space": "autocomplete" }
    });

    function getCompletions(token) {
        const prefix = token.string.trim();
        return prefix ? trie.search(prefix) : [];
    }

    CodeMirror.registerHelper('hint', 'javascript', (editor) => {
        const cursor = editor.getCursor();
        const token = editor.getTokenAt(cursor);
        const completions = getCompletions(token);

        if (completions.length === 0) {
            return;
        }

        return {
            list: completions,
            from: CodeMirror.Pos(cursor.line, token.start),
            to: CodeMirror.Pos(cursor.line, token.end)
        };
    });

    editor.on("inputRead", function(cm, event) {
        if (!cm.state.completionActive && /* Enforce autocompletion if input is a letter */
            event.text[0].match(/[\w@]/)) {
            CodeMirror.commands.autocomplete(cm, null, { completeSingle: false });
        }
    });
});
