export default function ParkingSlot({ data }) {
  return (
    <div
      className="slot"
      style={{
        backgroundColor: data.tipo === "pcd"
          ? (data.ocupada ? "#0044aa" : "#6ab6ff")
          : (data.ocupada ? "#ff5b5b" : "#6aff6a"),
      }}
    >
      <p>Vaga {data.id_vaga}</p>
      <strong>{data.ocupada ? "Ocupada" : "Livre"}</strong>
    </div>
  );
}