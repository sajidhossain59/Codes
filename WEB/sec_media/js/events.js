const $ = (selector, root = document) => root.querySelector(selector);
const $$ = (selector, root = document) => [...root.querySelectorAll(selector)];

let activeFilter = "all";

function showToast(message) {
  const toast = $("#toast");
  toast.textContent = message;
  toast.classList.add("show");
  window.setTimeout(() => toast.classList.remove("show"), 2000);
}

function applyFilters() {
  const query = $("#eventSearch").value.trim().toLowerCase();
  const category = $("#categoryFilter").value;
  const sort = $("#sortFilter").value;
  const cards = $("#eventGrid .event-card");
  const today = new Date();
  today.setHours(0, 0, 0, 0);
  let visible = 0;

  cards.forEach(card => {
    const eventDate = new Date(`${card.dataset.date}T00:00:00`);
    const isPast = eventDate < today;
    const isJoined = card.dataset.joined === "true";
    const searchable = `${card.dataset.title} ${card.dataset.category}`.toLowerCase();
    const matchesQuery = searchable.includes(query);
    const matchesCategory = category === "all" || card.dataset.category === category;
    const matchesTab =
      activeFilter === "all" ||
      (activeFilter === "upcoming" && !isPast) ||
      (activeFilter === "past" && isPast) ||
      (activeFilter === "joined" && isJoined);

    const show = matchesQuery && matchesCategory && matchesTab;
    card.hidden = !show;
    if (show) visible++;
  });

  const sorted = [...cards].sort((a, b) => {
    if (sort === "popular") return Number(b.dataset.popularity) - Number(a.dataset.popularity);
    return a.dataset.date.localeCompare(b.dataset.date);
  });
  sorted.forEach(card => $("#eventGrid").appendChild(card));

  $("#emptyState").hidden = visible !== 0;
  $("#eventCount").textContent = `${visible} event${visible === 1 ? "" : "s"}`;
}

function bindRsvp(button) {
  button.addEventListener("click", () => {
    const card = button.closest(".event-card, .list-card");
    const joined = !button.classList.contains("joined");
    button.classList.toggle("joined", joined);
    button.textContent = joined ? "✓ Going" : "I'm interested";

    const attending = $(".attending", card);
    if (attending) {
      const current = Number(attending.textContent.match(/\d+/)?.[0] || 0);
      attending.textContent = `◉ ${Math.max(0, current + (joined ? 1 : -1))} attending`;
      card.dataset.joined = String(joined);
    }
    showToast(joined ? "Added to your events" : "Removed from your events");
    if (activeFilter === "joined") applyFilters();
  });
}

function openModal() {
  $("#createModal").classList.add("open");
  $("#newEventName").focus();
}
function closeModal() {
  $("#createModal").classList.remove("open");
}

$("#filterTabs").addEventListener("click", event => {
  const button = event.target.closest("[data-filter]");
  if (!button) return;
  $$(".tab").forEach(tab => tab.classList.toggle("active", tab === button));
  activeFilter = button.dataset.filter;
  applyFilters();
});

$("#eventSearch").addEventListener("input", applyFilters);
$("#categoryFilter").addEventListener("change", applyFilters);
$("#sortFilter").addEventListener("change", applyFilters);
$$(".rsvp").forEach(bindRsvp);

$("#openCreate").addEventListener("click", openModal);
$("#cancelCreate").addEventListener("click", closeModal);
$("#createModal").addEventListener("click", event => {
  if (event.target.id === "createModal") closeModal();
});
document.addEventListener("keydown", event => {
  if (event.key === "Escape") closeModal();
});

$("#eventForm").addEventListener("submit", event => {
  event.preventDefault();

  const name = $("#newEventName").value.trim();
  const category = $("#newEventCategory").value;
  const date = $("#newEventDate").value;
  const time = $("#newEventTime").value;
  const location = $("#newEventLocation").value.trim();
  if (!name || !date || !time || !location) return;

  const parsedDate = new Date(`${date}T12:00:00`);
  const month = parsedDate.toLocaleString("en", { month: "short" }).toUpperCase();
  const day = String(parsedDate.getDate()).padStart(2, "0");

  const card = document.createElement("article");
  card.className = "event-card";
  Object.assign(card.dataset, {
    category, date, popularity: "0", joined: "false", title: name
  });

  const cover = document.createElement("div");
  cover.className = "event-cover";
  cover.style.backgroundImage = "linear-gradient(120deg,#343d70,#8a91d5)";
  const categoryLabel = document.createElement("span");
  categoryLabel.className = "category";
  categoryLabel.textContent = category.toUpperCase();
  const dateChip = document.createElement("span");
  dateChip.className = "date-chip";
  dateChip.append(document.createTextNode(month));
  const dayLabel = document.createElement("strong");
  dayLabel.textContent = day;
  dateChip.append(dayLabel);
  cover.append(categoryLabel, dateChip);

  const body = document.createElement("div");
  body.className = "event-body";
  const title = document.createElement("h3");
  title.textContent = name;
  const description = document.createElement("p");
  description.className = "description";
  description.textContent = "A new event shared with your campus community.";
  const meta = document.createElement("div");
  meta.className = "event-meta";
  meta.textContent = `◷ ${time}  ·  ⌖ ${location}`;
  const footer = document.createElement("div");
  footer.className = "event-footer";
  const count = document.createElement("span");
  count.className = "attending";
  count.textContent = "◉ 0 attending";
  const rsvp = document.createElement("button");
  rsvp.className = "rsvp";
  rsvp.textContent = "I'm interested";
  footer.append(count, rsvp);
  body.append(title, description, meta, footer);
  card.append(cover, body);

  $("#eventGrid").prepend(card);
  bindRsvp(rsvp);
  $("#eventForm").reset();
  closeModal();

  activeFilter = "all";
  $$(".tab").forEach(tab => tab.classList.toggle("active", tab.dataset.filter === "all"));
  $("#eventSearch").value = "";
  $("#categoryFilter").value = "all";
  applyFilters();
  showToast("Your event has been published");
});

$("#exploreButton").addEventListener("click", () => {
  $(".toolbar").scrollIntoView({ behavior: "smooth", block: "center" });
});

$$("[data-demo]").forEach(link => {
  link.addEventListener("click", event => {
    event.preventDefault();
    showToast(`${link.dataset.demo} is a demo feature`);
  });
});

applyFilters();