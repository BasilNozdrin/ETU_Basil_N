import React from 'react';
import {BrowserRouter as Router} from "react-router-dom";
import {Route} from "react-router";

import {
    Homepage,
    Game,
    Counter, Qsort
} from "./pages";

import "./styles.scss";

export class App extends React.Component {
  render() {
    return (
        <Router>
             <Route exact path="/" component={Homepage}/>
             <Route exact path="/game/" component={Game}/>
             <Route exact path="/dick/" component={Counter}/>
             <Route exact path="/qsort/" component={Qsort}/>
        </Router>
    );
  }
}
