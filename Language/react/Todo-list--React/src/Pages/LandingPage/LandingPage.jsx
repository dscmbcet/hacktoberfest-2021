import React from 'react'
import { Link } from 'react-router-dom'
import './LandingPage.css'

const LandingPage = () => {
    return (
        <div id="landingPage">
            <div id="mainSection">
                <h1>Welcome to To-do App!</h1>
                <Link id="button" to="/todos">Click here to enter</Link>
            </div>
        </div>
    )
}

export default LandingPage
