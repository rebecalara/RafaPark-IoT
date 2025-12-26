export default function StatusCard({ label, value }) {
  return (
    <div className="status-card">
      <h3>{label}</h3>
      <strong>{value}</strong>
    </div>
  );
}