const char menu_html[] =
R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="google" content="notranslate" />
<title>Communicator Menu</title>
<style>
:root {
  --bg:     #0f172a;
  --card:   #1e293b;
  --border: #334155;
  --text:   #e2e8f0;
  --muted:  #64748b;
  --cyan:   #22d3ee;
  --green:  #22c55e;
  --red:    #ef4444;
}
* { box-sizing: border-box; margin: 0; padding: 0; }
body {
  font-family: 'Segoe UI', system-ui, sans-serif;
  background: var(--bg);
  color: var(--text);
  padding: 16px;
  max-width: 480px;
  margin: 0 auto;
  min-height: 100vh;
}
a { color: var(--cyan); text-decoration: none; }
h1 {
  text-align: center;
  font-size: 1.3rem;
  color: var(--cyan);
  letter-spacing: 3px;
  text-transform: uppercase;
  margin-bottom: 4px;
}
.sub { text-align: center; color: var(--muted); font-size: 0.72rem; margin-bottom: 20px; }

.card {
  background: var(--card);
  border: 1px solid var(--border);
  border-radius: 14px;
  padding: 14px 16px;
  margin-bottom: 16px;
}
.card-title {
  font-size: 0.65rem;
  font-weight: 700;
  text-transform: uppercase;
  letter-spacing: 2px;
  color: var(--muted);
  margin-bottom: 10px;
}
.sect { margin-top: 16px; padding-top: 14px; border-top: 1px solid var(--border); }

/* H radio cards */
.hgrid { display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 8px; margin-bottom: 10px; }
.hcard {
  padding: 10px 4px 8px;
  background: var(--bg);
  border: 2px solid var(--border);
  border-radius: 10px;
  cursor: pointer;
  text-align: center;
  transition: border-color 0.2s, background 0.2s, box-shadow 0.2s;
  -webkit-tap-highlight-color: transparent;
  user-select: none;
}
.hcard:hover { border-color: var(--cyan); }
.hcard.sel  { border-color: var(--cyan);  background: #0e2d38;   box-shadow: 0 0 0 1px var(--cyan); }
.hcard.ton  { border-color: var(--green); background: #14532d33; box-shadow: 0 0 0 1px var(--green); }
.hcard .ico { font-size: 1.3rem; display: block; margin-bottom: 2px; }
.hcard .cod { font-size: 0.6rem; color: var(--cyan);  font-weight: 700; letter-spacing: 1px; display: block; }
.hcard.ton .cod { color: var(--green); }
.hcard .nam { font-size: 0.72rem; display: block; }

/* 2-column button grid */
.agrid { display: grid; grid-template-columns: 1fr 1fr; gap: 8px; }
/* 3-column button grid */
.agrid3 { display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 8px; }

.abtn, .tbtn {
  padding: 9px 6px;
  border: 1px solid var(--border);
  border-radius: 8px;
  background: var(--bg);
  color: var(--text);
  font-size: 0.82rem;
  cursor: pointer;
  text-align: center;
  transition: background 0.15s, transform 0.1s, border-color 0.15s, color 0.15s;
  -webkit-tap-highlight-color: transparent;
  user-select: none;
}
.abtn:hover          { background: #1e3a5f55; border-color: #3b82f6; }
.abtn:active, .tbtn:active { transform: scale(0.96); }
.abtn.danger         { border-color: #7f1d1d; color: #fca5a5; }
.abtn.danger:hover   { background: #7f1d1d44; border-color: var(--red); }
.tbtn                { border-color: var(--border); color: var(--muted); padding: 7px 6px; }
.tbtn.on             { border-color: var(--green); color: var(--green); background: #14532d33; }
.tbtn:hover          { background: #1e3a5f55; }
.tbtn.wide           { grid-column: 1 / -1; }

/* Toast */
#toast {
  position: fixed; bottom: 22px; left: 50%;
  transform: translateX(-50%) translateY(60px);
  background: var(--card); color: var(--text);
  padding: 9px 20px; border-radius: 20px;
  border: 1px solid var(--cyan); font-size: 0.82rem;
  opacity: 0; transition: transform 0.28s, opacity 0.28s;
  pointer-events: none; white-space: nowrap; z-index: 999;
}
#toast.show { transform: translateX(-50%) translateY(0); opacity: 1; }
</style>
</head>
<body>

<h1>Communicator</h1>
<p class="sub"><a href="/">&#8592; Main page</a></p>

<!-- ===== TOP CARD: Toggles + Logging + Actions ===== -->
<div class="card">

  <!-- Toggle buttons -->
  <div class="card-title">Toggle Settings</div>
  <div class="agrid">
    <button class="tbtn" id="t2"    data-cmd="O"  onclick="togbtn(this)">Display</button>
    <button class="tbtn" id="t3"    data-cmd="P"  onclick="togbtn(this)">Status LEDs</button>
    <button class="tbtn" id="t5"    data-cmd="X"  onclick="togbtn(this)">NTP</button>
    <button class="tbtn" id="t8"    data-cmd="}"  onclick="togbtn(this)">Ring Buffer Log</button>
    <button class="tbtn wide" id="tj" onclick="togDS3231()">DS3231 RTC</button>
  </div>
  <div id="rtcstatus" style="font-size:0.75em;color:#ccc;background:#333;padding:3px 6px;border-radius:4px;margin-top:6px;text-align:center;">RTC: loading...</div>

  <!-- Time logging -->
  <div class="sect">
    <div class="card-title">Time Logging</div>
    <div class="agrid">
      <button class="abtn" onclick="send('K')">LDR/sec</button>
      <button class="abtn" onclick="send('K1')">Time/min</button>
      <button class="abtn" onclick="send('K2')">Time/hour</button>
      <button class="abtn" onclick="send('K0')">Time/off</button>
    </div>
  </div>

  <!-- Log window -->
  <div class="sect">
    <div class="card-title">Log</div>
    <textarea id="lastlog" readonly style="font-family:monospace;font-size:0.72rem;color:var(--text);background:var(--bg);border:1px solid var(--border);border-radius:8px;padding:6px;box-sizing:border-box;height:110px;width:100%;resize:none;"></textarea>
  </div>

  <!-- Action buttons -->
  <div class="sect">
    <div class="card-title">Actions</div>
    <div class="agrid">
      <button class="abtn" onclick="send('G')">&#128246; Scan WIFI</button>
      <button class="abtn" onclick="send('!')">&#128336; RTC Info</button>
      <button class="abtn" onclick="send('&')">&#128257; RTC Update</button>
      <button class="abtn" onclick="send('Z')">&#128246; WPS</button>
      <button class="abtn" onclick="send('{')">&#128247; Learn IR</button>
      <button class="abtn" onclick="send('I')">&#128203; Version</button>
      <button class="abtn danger" onclick="cfm('R','Reset all settings to default?')">&#9888; Reset</button>
      <button class="abtn danger" onclick="cfm('@','Restart the device now?')">&#128257; Restart</button>
    </div>
  </div>

</div>

<!-- ===== INPUT METHOD CARD ===== -->
<div class="card">
  <div class="card-title">Input Method &mdash; select one (H00&ndash;H05)</div>
  <div class="hgrid">
    <div class="hcard" id="h00" onclick="selH('H00','h00')">
      <span class="ico">&#8709;</span>
      <span class="cod">H00</span>
      <span class="nam">None / NTP</span>
    </div>
    <div class="hcard" id="h01" onclick="selH('H01','h01')">
      <span class="ico">&#128260;</span>
      <span class="cod">H01</span>
      <span class="nam">Rotary</span>
    </div>
    <div class="hcard" id="h02" onclick="selH('H02','h02')">
      <span class="ico">&#128306;</span>
      <span class="cod">H02</span>
      <span class="nam">Membrane</span>
    </div>
    <div class="hcard" id="h03" onclick="selH('H03','h03')">
      <span class="ico">&#127894;</span>
      <span class="cod">H03</span>
      <span class="nam">IR Large</span>
    </div>
    <div class="hcard" id="h04" onclick="selH('H04','h04')">
      <span class="ico">&#127899;</span>
      <span class="cod">H04</span>
      <span class="nam">IR Tiny</span>
    </div>
    <div class="hcard" id="h05" onclick="togH05()">
      <span class="ico">&#8986;</span>
      <span class="cod">H05</span>
      <span class="nam">Time Receiver</span>
    </div>
  </div>
  <p style="font-size:0.68rem;color:var(--muted);">&#9888; Restart required after H00&ndash;H04 change</p>
</div>

<div id="toast"></div>

<script>
// ── Load state from device ────────────────────────────────
function loadState() {
  fetch('/menustate')
    .then(function(r) { return r.json(); })
    .then(function(s) {
      document.querySelectorAll('.tbtn').forEach(function(b) {
        if (s[b.id] === 1) b.classList.add('on'); else b.classList.remove('on');
      });
      document.querySelectorAll('.hcard').forEach(function(c) { c.classList.remove('sel'); });
      var hel = document.getElementById(s.hi);
      if (hel) hel.classList.add('sel');
      var h05 = document.getElementById('h05');
      if (s.t9 === 1) h05.classList.add('ton'); else h05.classList.remove('ton');
      var hw  = s.ds3231hw ? 'DS3231 installed' : 'DS3231 not found';
      var src = 'Active: ' + (s.rtcsrc || 'ESP32');
      document.getElementById('rtcstatus').textContent = hw + ' · ' + src;
      document.getElementById('tj').textContent = s.ds3231hw ? 'Use DS3231 RTC' : 'Use ESP32 RTC';
    })
    .catch(function() {});
}
loadState();

// ── Button handlers ───────────────────────────────────────
function togbtn(el) { el.classList.toggle('on'); send(el.getAttribute('data-cmd')); setTimeout(loadState, 300); }

function togDS3231() { send('J'); setTimeout(loadState, 300); }

function togH05() {
  var el = document.getElementById('h05');
  el.classList.toggle('ton');
  send('H05');
}

function selH(cmd, elId) {
  document.querySelectorAll('.hcard').forEach(function(c) { c.classList.remove('sel'); });
  document.getElementById(elId).classList.add('sel');
  send(cmd);
}

function send(cmd) {
  fetch('/get?input1=' + encodeURIComponent(cmd)).catch(function(){});
  showToast('Sent: ' + cmd);
}

function cfm(cmd, msg) { if (confirm(msg)) send(cmd); }

function showToast(msg) {
  var t = document.getElementById('toast');
  t.textContent = msg;
  t.classList.add('show');
  setTimeout(function() { t.classList.remove('show'); }, 1800);
}

// ── Log window ────────────────────────────────────────────
function fetchLastLog() {
  fetch('/tekstprint').then(function(r){return r.text();}).then(function(t){
    var lines = t.split('\n').filter(function(l){return l.trim()!='';});
    var el = document.getElementById('lastlog');
    var atBottom = (el.scrollHeight - el.scrollTop - el.clientHeight) < 30;
    el.value = lines.slice(-50).join('\n');
    if (atBottom) el.scrollTop = el.scrollHeight;
  }).catch(function(){});
  setTimeout(fetchLastLog, 5000);
}
fetchLastLog();
</script>

</body>
</html>
)rawliteral";
