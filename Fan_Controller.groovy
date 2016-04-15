/**
 *  Spark Core
 *
 *  Copyright 2015 TOM FORTI
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
 *  in compliance with the License. You may obtain a copy of the License at:
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software distributed under the License is distributed
 *  on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License
 *  for the specific language governing permissions and limitations under the License.
 *
 */
/**
 *  PHOTON Fan
 *
 *  Author: tomforti@gmail.com
 *  Date: 2015-11-12
 */
 
preferences {
    input("token", "text", title: "Access Token")
    input("deviceId", "text", title: "Device ID")
    input("fannum", "text", title: "Relay Number 1-4")
}
 
 // for the UI
metadata {
	definition (name: "PHOTON FAN", author: "tomforti@gmail.com") {
    	capability "Switch"
        capability "Relay Switch"
        
        command "lowSpeed"
        command "medSpeed"
        command "highSpeed"
        command "light"
        
        attribute "currentSpeed", "string"
	}

    // tile definitions
tiles 
{
        standardTile("switch", "device.switch", width: 2, height: 2, canChangeIcon: true) 
        {
			state "off", label: '${name}', action: "switch.on", icon:"st.Lighting.light24", backgroundColor: "#ffffff", nextState: "on"
			state "on", label: '${name}', action: "switch.off", icon:"st.Lighting.light24", backgroundColor: "#79b821"    

		}
        
        standardTile("light", "device.level", width: 1, height: 1, canChangeIcon: true) 
        {
			state "off", label: 'Light', action: "light", icon:"st.Lighting.light20", backgroundColor: "#ffffff", nextState: "on"
			state "on", label: 'Light', action: "light", icon:"st.Lighting.light20", backgroundColor: "#79b821"    

		}
        
        //displays current speed as off, low, med, high
        valueTile("currentSpeed", "device.currentSpeed", canChangeIcon: false, inactiveLabel: false, decoration: "flat") 
        {
            state ("default", label:'${currentValue}')
        }

		//Speed control row
        standardTile("lowSpeed", "device.level", inactiveLabel: false, decoration: "flat") 
        {
            state "lowSpeed", label:'LOW', action:"lowSpeed", icon:"st.Home.home30"
        }
        standardTile("medSpeed", "device.level", inactiveLabel: false, decoration: "flat") 
        {
            state "medSpeed", label:'MED', action:"medSpeed", icon:"st.Home.home30"
        }
        standardTile("highSpeed", "device.level", inactiveLabel: false, decoration: "flat") 
        {
            state "highSpeed", label:'HIGH', action:"highSpeed", icon:"st.Home.home30"
        }

		main(["switch"])
		details(["switch", "light", "currentSpeed", "lowSpeed", "medSpeed", "highSpeed"])
	}
}

def parse(String description) {
	log.error "This device does not support incoming events"
	return null
}

def on() 
{
	sendEvent(name: "switch", value: "on", isStateChange: true, display: false)
    log.info "Fan Med"
    sendEvent(name: "currentSpeed", value: "MED" as String)
	put '2'
}

def off() 
{
	sendEvent(name: "switch", value: "off", isStateChange: true, display: false)
    log.info "Fan off"
  	sendEvent(name: "currentSpeed", value: "OFF" as String)
	put '0'
}

def lowSpeed() 
{
	put '1'
    sendEvent(name: "switch", value: "on", isStateChange: true, display: false)
	log.info "Fan low"
    sendEvent(name: "currentSpeed", value: "LOW" as String)
}

def medSpeed() 
{
	put '2'
    sendEvent(name: "switch", value: "on", isStateChange: true, display: false)
    log.info "Fan Med"
    sendEvent(name: "currentSpeed", value: "MED" as String)
}

def highSpeed() 
{
	put '3'
    sendEvent(name: "switch", value: "on", isStateChange: true, display: false)
    log.info "Fan High"
    sendEvent(name: "currentSpeed", value: "HIGH" as String)
}    

def light()
{
	put '4'
    sendEvent(name: "switch", value: "on", isStateChange: true, display: false)
    log.info "Fan Light"
}

private put(fanstate) 
{
    //Spark Core API Call
	httpPost(
		uri: "https://api.spark.io/v1/devices/${deviceId}/stfan${fannum}",
        body: [access_token: token, command: fanstate],  
		) 
    {response -> log.debug (response.data)}
}
