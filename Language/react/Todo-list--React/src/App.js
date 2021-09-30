import React from 'react';
import './App.css';
import {
  BrowserRouter as Router,
  Switch,
  Route
} from "react-router-dom";

import TodoApp from './components/TodoApp/TodoApp';
import LandingPage from './components/TodoApp/Pages/LandingPage/LandingPage';
import navbar from './components/TodoApp/navbar'

function App() {
  return (
    <Router>
      <Switch>
        <navbar/>
        <Route path="/" exact>
          <LandingPage />
        </Route>
        <Route path="/todo">
          <TodoApp />
        </Route>

      </Switch>
    </Router>


  );
}

export default App;
