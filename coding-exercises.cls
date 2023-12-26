\ProvidesClass{coding-exercises}[2023/12/23 Übungsaufgaben Programmieren in C]
\LoadClass[
  %twoside,             % Layout fuer beidseitigen Druck
  openany,              % Um leere Seiten zu vermeiden
  headsepline,          % horizontale Linie unter Kolumnentitel
  chapterprefix=false,
  BCOR=15mm,		    % Korrektur fuer die Bindung
  DIV=15,		  	    % DIV-Wert fuer die Erstellung des
  			            % Satzspiegels, siehe scrguide
  fontsize=12pt,        % Schriftgröße
  a4paper,
]{scrbook}

\usepackage[ngerman]{babel}

%%% Schrift auswählen
\usepackage{XCharter}
\usepackage{FiraSans}
\usepackage{fontspec}
\setmonofont{DejaVu Sans Mono}[Scale=0.9]
%\setmonofont{inconsolata}
%\setmonofont{JetBrains Mono}
\setmainfont{XCharter}
\newfontfamily{\lato}{Lato}



\usepackage[%
  headsepline=0.5pt:0pt,  % Aktiviert eine Linie unter der Kopfzeile
                          % Breite 0.5pt, Abstand zwischen der Kopfzeile und der
                          % Linie 0 Punkt
  automark,               % automatische Markierung von Kopf- und Fußzeilen
  pagestyleset=KOMA-Script,
  markcase=ignoreuppercase  % Text in Kopf- und Fußzeilen wird nicht in
                            % Großbuchstaben umgewandelt
]{scrlayer-scrpage}
\pagestyle{scrheadings}    % Kopf- und Fußzeilen
\clearpairofpagestyles     % Löscht die aktuellen Einstellungen für Kopf- und Fußzeilen
\ohead{\pagemark}          % Äußerer Kopf: Seitenzahl
\ihead{\headmark}          % Innerer Kopf: Kapitelname
\ofoot[]{}                 % Äußerer Fuß: leer
\automark[section]{chapter}% Kopfzeile: [rechts]{links}
\setkomafont{pagehead}{\normalfont} % Schriftart für Kopfzeile
% \setkomafont{pagefoot}{\normalfont} % Schriftart für Fußzeile
\setcounter{secnumdepth}{4}% Gliederungsebenen
\setcounter{tocdepth}{4}   % Gliederungsebenen im Inhaltsverzeichnis


%%% Statt der standardmäßigen Umschaltung bei KOMAscript auf serifenlose
%%% Schrift bei Kapitel-, Sectionüberschriften, etc. lieber Standardschrift
%%% verwenden
\setkomafont{disposition}{\lato}
\setkomafont{pageheadfoot}{\lato}
\setkomafont{pagenumber}{\lato}
%\setkomafont{disposition}{\normalfont}
%\setkomafont{pageheadfoot}{\normalfont}
%\setkomafont{pagenumber}{\normalfont}

\usepackage{%
  ellipsis,	% Korrigiert den Weißraum um Auslassungspunkte
  ragged2e,	% Ermöglicht Flattersatz mit Silbentrennung
  marginnote	% Für bessere Randnotizen mit \marginnote statt
		% \marginline
}

%%% Umbrüche verbessern
\usepackage[%
  expansion=true,
  protrusion=true
]{microtype}

%%% Zeilenabstand leicht erhöhen
\usepackage{setspace}
  \setstretch{1.07}
  \recalctypearea

%%% Schusterjungen vermeiden (Seitenumbruch direkt nach erster Zeile eines
%%% neuen Absatzes)
\clubpenalty=10000

%%% Hurenkinder vermeiden (Letzte Zeile eines Absatzes landet auf neuer Seite)
\widowpenalty=10000
\displaywidowpenalty=10000

\usepackage{amssymb} % Für Symbole wie \bullet und \circ
\usepackage[all, error]{onlyamsmath}

%%% Unterschriften für Tabellen und Abbildungen: Typ ("Figure 3.4:" oder
%%% "Table 1.2:") fettschreiben, dahinter kursiv
\usepackage[bf]{caption}
\renewcommand{\captionfont}{\itshape}

\usepackage{xcolor}
\definecolor{hellgrau}{HTML}{F2F2F2}    % hellgrau
\definecolor{dunkelgrau}{HTML}{707070}  % dunkelgrau
\definecolor{weiss}{HTML}{FFFFFF}       % weiß

\usepackage[setspace=false]{scrhack} % für minted-Paket benötigt
\usepackage{minted}

\setminted[c]{
    bgcolor=hellgrau,
    %fontsize=\small,
    breaklines,
    %linenos,
    style=friendly
}
\setmintedinline{
    bgcolor={},
    %fontsize=\small,
    breaklines,
    style=friendly
}


\usepackage[german=guillemets]{csquotes}
\MakeOuterQuote{"}

\usepackage{fontawesome}
\usepackage{etoolbox} % Für \ifstrequal
\usepackage{tcolorbox} % Für die Box-Umgebung
\newtcolorbox{mybox}[2][]{
  colback=hellgrau,
  colframe=dunkelgrau,
  fontupper=\ttfamily\obeylines,  % \obeylines berücksichtigt
                                  % Zeilenumbrüche im Eingabetext
  boxrule=0.9pt,  % Dicke des Rahmens der Box
  boxsep=5pt,     % Abstand zwischen dem Inhalt der Box und ihrem Rahmen
  arc=1pt,        % Radius der Ecken der Box
  coltitle=weiss,
  colbacktitle=dunkelgrau,
  fonttitle=\sffamily,
  toptitle=1mm,     % Abstand vom oberen Rand des Titelbereichs zur Titelzeile
  bottomtitle=1mm,  % Abstand vom unteren Rand des Titelbereichs zur Titelzeile
  % Wenn der zweite Parameter von mybox `file` ist, wird das Dateisymbol
  % verwendet, wenn der zweite Parameter von mybox `console` ist, wird das
  % Terminal-Symbol verwendet, und wenn es keines von beiden ist, wird kein
  % Symbol eingefügt
  title={%
    \ifstrequal{#2}{file}{\faFileTextO\hspace{5mm}}{%
      \ifstrequal{#2}{console}{\faTerminal\hspace{5mm}}{}%
    }#1       % Der erste Parameter ist der Titel in der Titelzeile
  },
  left=3pt,   % Abstand des Inhalts der Box vom linken Innenrand der Box
  right=3pt,  % Abstand des Inhalts der Box vom rechten Innenrand der Box
  before upper={\DisableQuotes}, % Deaktiviert Guillemets in der Box
  after upper={\EnableQuotes}    % Stellt Guillemets nach der Box wieder her
}


%%% Nummerierung (a), (b), etc. verwenden
\renewcommand{\labelenumi}{(\alph{enumi})}

\usepackage{pgffor}
\newcommand{\TopicLevel}[2]{%
    \noindent\makebox[\textwidth]{%
    \sffamily%
    \textbf{Thema:} #1 \hfill \textbf{Schwierigkeitsgrad:}
    \foreach \n in {1,...,#2}{\Large\textbf{$\bullet$}}%
    \foreach \n in {1,...,\numexpr5-#2}{\Large\textbf{$\circ$}}%
    }%
}

\usepackage{datetime2}


\usepackage[
  raiselinks=true,        % Hebt Links an, um sie auf die Höhe der Linie zu
                          % bringen (nützlich für Links in der Fußzeile)
  bookmarks=true,         % Erzeugt Lesezeichen im PDF
  bookmarksopenlevel=0,   % Setzt das Level der Lesezeichen, die im PDF-Viewer
                          % standardmäßig geöffnet sind (0 = root level)
  bookmarksopen=true,     % Öffnet alle Lesezeichen im PDF-Viewer
  bookmarksnumbered=true, % Fügt Nummerierung zu den Lesezeichen hinzu
  hyperindex=true,        % Macht Einträge im Index klickbar
  hypertexnames=false,    % Deaktiviert die Verwendung von TeX-Namen für Links.
                          % Kann helfen, Probleme mit gleichnamigen Links zu
                          % verhindern.
  plainpages=false,       % Verhindert Probleme bei der Seitennummerierung
                          % (wichtig, wenn Text und arabische Seitenzahlen
                          % gemischt sind).
  pdfpagelabels=true,     % Nutzt LaTeX-Seitenlabels für PDF-Seitenlabels
                          % (z.B. römische Ziffern, arabische Zahlen)
  pdfpagelayout=SinglePage, % Setzt das Layout des PDFs auf Einzelseitenansicht
  pdfborder={0 0 0}       % Setzt die Rahmenbreite der Links auf 0,
                          % entfernt also Rahmen um die Links
]{hyperref}
\usepackage[pdftex]{thumbpdf}

\newcommand{\Vorlage}{
    \vspace{\baselineskip} % Doppelter Zeilenabstand zum vorherigen Text
    \noindent\textsf{Vorlage:}
    %\vspace{-\baselineskip} % Entfernt den zusätzlichen Abstand zur minted-Umgebung
}

\usepackage{tikz}
\usetikzlibrary{shapes.multipart, positioning, arrows.meta}
