import React from 'react';
import './App.css';
import AddEntry from '../AddEntry.jsx';
import CurrentEntries from '../CurrentEntries.jsx';
import Dropdown from "./Dropdown";
//import React, { useState } from "react";
//import DatePicker from "react-datepicker";
//import "react-datepicker/dist/react-datepicker.css";


function App() {

	
	const options = [
		{value: "volunteersByFrequency", label: "Show Volunteers by Frequency" },
		{value: "volunteersByDate", label: "Show Volunteers by Date" },
		{value: "datesByVolunteer", label: "Show Dates by Volunteer" }
	];
	
//	const [date, setDate] = useState(new Date());


  return (
    <div className="App">
      <h1>Entries</h1>

      <AddEntry />
      <hr />
      <CurrentEntries />
      <hr />

      <Dropdown placeHolder="Select..." options={options}/>
    </div>
  )
}

export default App;

